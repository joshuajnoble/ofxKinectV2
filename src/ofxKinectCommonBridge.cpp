#include "ofxKinectCommonBridge.h"

//================================================================================================================
// common bridge
//================================================================================================================


ofxKinectCommonBridge::ofxKinectCommonBridge(){
	hKinect = NULL;

	pDepthFrame = NULL;
	pColorFrame = NULL;

	beginMappingColorToDepth = false;
	bNeedsUpdateSkeleton = false;
	bUsingBodyIndex = false;
	bIsFrameNewVideo = false;
	bNeedsUpdateVideo = false;
	bIsFrameNewDepth = false;
	bNeedsUpdateDepth = false;
	bVideoIsInfrared = false;
	bInited = false;
	bStarted = false;

	mappingColorToDepth = false;
	mappingDepthToColor = false;

	bUsingSkeletons = false;
  	bUseTexture = true;
	bProgrammableRenderer = false;
	
	setDepthClipping();
}

//---------------------------------------------------------------------------
void ofxKinectCommonBridge::setDepthClipping(float nearClip, float farClip){
	nearClipping = nearClip;
	farClipping = farClip;
	updateDepthLookupTable();
}

//---------------------------------------------------------------------------
void ofxKinectCommonBridge::updateDepthLookupTable()
{
	unsigned char nearColor = bNearWhite ? 255 : 0;
	unsigned char farColor = bNearWhite ? 0 : 255;
	unsigned int maxDepthLevels = 10001;
	depthLookupTable.resize(maxDepthLevels);
	depthLookupTable[0] = 0;
	for(unsigned int i = 1; i < maxDepthLevels; i++)
	{
		depthLookupTable[i] = ofMap(i, nearClipping, farClipping, nearColor, farColor, true);
	}
}

/// is the current frame new?
bool ofxKinectCommonBridge::isFrameNew(){
	return isFrameNewVideo() || isFrameNewDepth();
}

bool ofxKinectCommonBridge::isFrameNewVideo(){
	return bIsFrameNewVideo;
}

bool ofxKinectCommonBridge::isFrameNewDepth(){
	return bIsFrameNewDepth;
}
//
//bool ofxKinectCommonBridge::isNewSkeleton() {
//	return bNeedsUpdateSkeleton;
//}
//
//vector<Skeleton> &ofxKinectCommonBridge::getSkeletons() {
//	return skeletons;
//}
/// updates the pixel buffers and textures
/// make sure to call this to update to the latest incoming frames
void ofxKinectCommonBridge::update()
{
	if(!bStarted)
	{
		ofLogError("ofxKinectCommonBridge::update") << "Kinect not started";
		return;
	}

	// update color or IR pixels and textures if necessary
	if(bNeedsUpdateVideo)
	{
		bIsFrameNewVideo = true;
		bNeedsUpdateVideo = false;

		if(bUseTexture) {
			if(bVideoIsInfrared) 
			{
				if(bProgrammableRenderer){
					videoTex.loadData(videoPixels.getPixels(), colorFrameDescription.width, colorFrameDescription.height, GL_RED);
				} else {
					videoTex.loadData(videoPixels.getPixels(), colorFrameDescription.width, colorFrameDescription.height, GL_LUMINANCE16);
				}
			} 
			else 
			{
				if( bProgrammableRenderer ) {
					// programmable renderer likes this
					// TODO
					// swizzle this to rgb & a -> GL_ONE
					videoTex.loadData(videoPixels.getPixels(), colorFrameDescription.width, colorFrameDescription.height, GL_BGRA);
				} else {
					videoTex.loadData(videoPixels.getPixels(), colorFrameDescription.width, colorFrameDescription.height, GL_RGBA);
				}
			}
		}
	} else {
		bIsFrameNewVideo = false;
	}


	// update depth pixels and texture if necessary
	if(bNeedsUpdateDepth){

		if(mappingColorToDepth) {
			beginMappingColorToDepth = true;
		}

		bIsFrameNewDepth = true;
		//swap(depthPixelsRaw, depthPixelsRawBack);
		bNeedsUpdateDepth = false;

		for(int i = 0; i < depthPixels.getWidth()*depthPixels.getHeight(); i++) {
			depthPixels[i] = depthLookupTable[ ofClamp(depthPixelsRaw[i] >> 4, 0, depthLookupTable.size()-1 ) ];
			depthPixelsRaw[i] = depthPixelsRaw[i] >> 4;
		}
		//}


		if(bUseTexture) {
			//depthTex.loadData(depthPixels.getPixels(), K2_IR_WIDTH, K2_IR_HEIGHT, GL_LUMINANCE);
			if( bProgrammableRenderer ) {
				depthTex.loadData(depthPixels.getPixels(), depthFrameDescription.width, depthFrameDescription.height, GL_RED);
				rawDepthTex.loadData(depthPixelsRaw.getPixels(), depthFrameDescription.width, depthFrameDescription.height, GL_RED);
			} else {
				depthTex.loadData(depthPixels.getPixels(), depthFrameDescription.width, depthFrameDescription.height, GL_LUMINANCE);
				rawDepthTex.loadData(depthPixelsRaw.getPixels(), depthFrameDescription.width, depthFrameDescription.height, GL_LUMINANCE16);
			}
		}
	} else {
		bIsFrameNewDepth = false;
	}

	// update skeletons if necessary
	if(bUsingSkeletons && bNeedsUpdateSkeleton)
	{	

	//	bIsSkeletonFrameNew = true;
	//	bNeedsUpdateSkeleton = false;
	//	bool foundSkeleton = false;

		for ( int i = 0; i < 6; i++ ) 
		{
			/*if (skeletonBackBuffer[i].size() > 0)
			{

				for (int j = 0; j < JointType_Count; j++)
				{
					if (skeletonBackBuffer[i].at(j).trackingState == TrackingState_Tracked || skeletonBackBuffer[i].at(j).trackingState == TrackingState_Inferred)
					{
						cout << skeletonBackBuffer[i].at(j).kcbJoint.Position.X << " " << skeletonBackBuffer[i].at(j).kcbJoint.Position.Y << " ";
					}
				}

			}*/

		}
	//


	} else {
		bNeedsUpdateSkeleton = false;
	}


	if (bNeedsUpdateBodyIndex)
	{
		
		swap(bodyIndexPixelsBack, bodyIndexPixels);

		if (bProgrammableRenderer)
		{
			bodyIndexTex.loadData(bodyIndexPixels, GL_R8);
		}
		else
		{
			bodyIndexTex.loadData(bodyIndexPixels, GL_LUMINANCE);
		}

		bNeedsUpdateBodyIndex = false;
	}
}

//------------------------------------
ofPixels& ofxKinectCommonBridge::getColorPixelsRef(){
	return videoPixels;
}

//------------------------------------
ofPixels & ofxKinectCommonBridge::getDepthPixelsRef(){       	///< grayscale values
	return depthPixels;
}

//------------------------------------
ofShortPixels & ofxKinectCommonBridge::getRawDepthPixelsRef(){
	return depthPixelsRaw;
}

//------------------------------------
void ofxKinectCommonBridge::setUseTexture(bool bUse){
	bUseTexture = bUse;
}

//----------------------------------------------------------
void ofxKinectCommonBridge::draw(float _x, float _y, float _w, float _h) {
	if(bUseTexture) {
		videoTex.draw(_x, _y, _w, _h);
	}
}

//----------------------------------------------------------
void ofxKinectCommonBridge::draw(float _x, float _y) {
	draw(_x, _y, colorFrameDescription.width, colorFrameDescription.height);
}

//----------------------------------------------------------
void ofxKinectCommonBridge::draw(const ofPoint & point) {
	draw(point.x, point.y);
}

//----------------------------------------------------------
void ofxKinectCommonBridge::draw(const ofRectangle & rect) {
	draw(rect.x, rect.y, rect.width, rect.height);
}

//----------------------------------------------------------
void ofxKinectCommonBridge::drawRawDepth(float _x, float _y, float _w, float _h) {
	if(bUseTexture) {
		rawDepthTex.draw(_x, _y, _w, _h);
	}
}

//----------------------------------------------------------
void ofxKinectCommonBridge::drawRawDepth(float _x, float _y) {
	drawRawDepth(_x, _y, depthFrameDescription.width, depthFrameDescription.height);
}

//----------------------------------------------------------
void ofxKinectCommonBridge::drawRawDepth(const ofPoint & point) {
	drawRawDepth(point.x, point.y);
}

//----------------------------------------------------------
void ofxKinectCommonBridge::drawRawDepth(const ofRectangle & rect) {
	drawRawDepth(rect.x, rect.y, rect.width, rect.height);
}

//----------------------------------------------------------
void ofxKinectCommonBridge::drawDepth(float _x, float _y, float _w, float _h) {
	if(bUseTexture) {
		depthTex.draw(_x, _y, _w, _h);
	}
}

//---------------------------------------------------------------------------
void ofxKinectCommonBridge::drawDepth(float _x, float _y) {
	drawDepth(_x, _y, (float) depthFrameDescription.width, (float) depthFrameDescription.height);
}

//----------------------------------------------------------
void ofxKinectCommonBridge::drawDepth(const ofPoint & point) {
	drawDepth(point.x, point.y);
}

//----------------------------------------------------------
void ofxKinectCommonBridge::drawDepth(const ofRectangle & rect) {
	drawDepth(rect.x, rect.y, rect.width, rect.height);
}

//----------------------------------------------------------
void ofxKinectCommonBridge::drawBodyIndex(float x, float y) {
	bodyIndexTex.draw(x, y);
}

//
void ofxKinectCommonBridge::drawSkeleton( int index )
{
	// Iterate through skeletons
	uint32_t i = 0;
	if(index >= skeletons.size())
	{
		ofLog() << " skeleton index too high " << endl;
		return;
	}

	ofVec3f lastPosition(-1,-1,-1);

	// Iterate through joints
	for ( Skeleton::iterator it = skeletons.at(index).begin(); it != skeletons.at(index).end(); ++it ) 
	{

		//// Get position and rotation
		//Joint joint = it->second;

		//ofSetColor(255, 255, 255);
		//ofSetLineWidth(3.0); // fat lines
		////int startJoint = joint.getStartJoint();
		////// do we have a start joint?
		//if ( lastPosition.z != -1 ) // this is dum 
		//{
		//	// draw the line
		//	ofLine(lastPosition, ofVec3f(joint.Position.X, joint.Position.Y, joint.Position.Z));
		//}

		////ofSetColor(255, 0, 0);
		////// Draw joint
		////ofCircle( bone.getScreenPosition(), 10 );

		//ofSetColor(255, 0, 0);
		//ofCircle(ofVec3f(joint.Position.X, joint.Position.Y, joint.Position.Z), 10);

		//lastPosition.set(joint.Position.X, joint.Position.Y, joint.Position.Z);
	}

	ofSetColor(255, 255, 255);
}


bool ofxKinectCommonBridge::initSensor( int id )
{
	if(bStarted){
		ofLogError("ofxKinectCommonBridge::initSensor") << "Cannot configure once the sensor has already started" << endl;
		return false;
	}
	if (ofGetCurrentRenderer()->getType() == ofGLProgrammableRenderer::TYPE)
	{
		bProgrammableRenderer = true;
	}

	hKinect = KCBOpenDefaultSensor();

	return true;
}

bool ofxKinectCommonBridge::initDepthStream( bool mapDepthToColor )
{

	mappingDepthToColor = mapDepthToColor;

	if(bStarted){
		ofLogError("ofxKinectCommonBridge::initDepthStream") << " Cannot configure once the sensor has already started";
		return false;
	}

	HRESULT hr;
	hr = KCBGetDepthFrameDescription(hKinect, &depthFrameDescription);

	//hr = KCBCreateDepthFrame(depthFrameDescription, &pDepthFrame);

	if(bProgrammableRenderer) {
		depthPixels.allocate(depthFrameDescription.width, depthFrameDescription.height, OF_IMAGE_COLOR);
		depthPixelsBack.allocate(depthFrameDescription.width, depthFrameDescription.height, OF_IMAGE_COLOR);
	} else {
		depthPixels.allocate(depthFrameDescription.width, depthFrameDescription.height, OF_IMAGE_GRAYSCALE);
		depthPixelsBack.allocate(depthFrameDescription.width, depthFrameDescription.height, OF_IMAGE_GRAYSCALE);
	}

	depthPixelsRaw.allocate(depthFrameDescription.width, depthFrameDescription.height, OF_IMAGE_GRAYSCALE);
	depthPixelsRawBack.allocate(depthFrameDescription.width, depthFrameDescription.height, OF_IMAGE_GRAYSCALE);

	pDepthFrame = new KCBDepthFrame();
	pDepthFrame->Buffer = depthPixelsRaw.getPixels();
	pDepthFrame->Size = depthFrameDescription.lengthInPixels;

	if(bUseTexture){

		if(bProgrammableRenderer) {
			//int w, int h, int glInternalFormat, bool bUseARBExtention, int glFormat, int pixelType
			depthTex.allocate(depthFrameDescription.width, depthFrameDescription.height, GL_R8);//, true, GL_R8, GL_UNSIGNED_BYTE);
			depthTex.setRGToRGBASwizzles(true);

			//rawDepthTex.allocate(K2_IR_WIDTH, K2_IR_HEIGHT, GL_R16, true, GL_RED, GL_UNSIGNED_SHORT);
			rawDepthTex.allocate(depthPixelsRaw, true);
			rawDepthTex.setRGToRGBASwizzles(true);

			cout << rawDepthTex.getWidth() << " " << rawDepthTex.getHeight() << endl;
			//depthTex.allocate(K2_IR_WIDTH, K2_IR_HEIGHT, GL_RGB);
		} else {
			depthTex.allocate(depthFrameDescription.width, depthFrameDescription.height, GL_LUMINANCE);
			rawDepthTex.allocate(depthFrameDescription.width, depthFrameDescription.height, GL_LUMINANCE16);
		}
	}
	
	
	return bInited;
}

bool ofxKinectCommonBridge::initColorStream( bool mapColorToDepth )
{

	KCBGetColorFrameDescription(hKinect, ColorImageFormat_Rgba, &colorFrameDescription);

	videoPixels.allocate(colorFrameDescription.width, colorFrameDescription.height, OF_IMAGE_COLOR_ALPHA);
	videoPixelsBack.allocate(colorFrameDescription.width, colorFrameDescription.height, OF_IMAGE_COLOR_ALPHA);
	if(bUseTexture){
		videoTex.allocate(colorFrameDescription.width, colorFrameDescription.height, GL_BGRA);
	}


	pColorFrame = new KCBColorFrame();
	pColorFrame->Buffer = videoPixels.getPixels();
	pColorFrame->Size = colorFrameDescription.lengthInPixels * colorFrameDescription.bytesPerPixel;
	pColorFrame->Format = ColorImageFormat_Rgba;

	//HRESULT hr = KCBCreateColorFrame(ColorImageFormat_Rgba, colorFrameDescription, &pColorFrame);
	return true;
}

bool ofxKinectCommonBridge::initIRStream( int width, int height )
{
	if(bStarted){
		ofLogError("ofxKinectCommonBridge::startIRStream") << " Cannot configure when the sensor has already started";
		return false;
	}

	bVideoIsInfrared = true;

	KCBGetInfraredFrameDescription(hKinect, &irFrameDescription);

	irPixelsRaw.allocate(irFrameDescription.width, irFrameDescription.height, OF_IMAGE_GRAYSCALE);

	pInfraredFrame = new KCBInfraredFrame();
	pInfraredFrame->Buffer = irPixelsRaw.getPixels();
	pInfraredFrame->Size = irFrameDescription.lengthInPixels;

	if(bUseTexture)
	{
		if(bProgrammableRenderer){
			videoTex.allocate(irFrameDescription.width, irFrameDescription.height, GL_R8);
			videoTex.setRGToRGBASwizzles(true);
		}
		else{
			videoTex.allocate(irFrameDescription.width, irFrameDescription.height, GL_LUMINANCE);
		}
	}

	//HRESULT hr = KCBCreateInfraredFrame(irFrameDescription, &pInfraredFrame);
	//if (hr >= 0){
	//	bInited = true;
	//	return true;
	//}

	bInited = true;
	ofLogError("ofxKinectCommonBridge::initSkeletonStream") << "cannot initialize stream";
	return true;
}

bool ofxKinectCommonBridge::initBodyIndexStream()
{
	if (bStarted){
		ofLogError("ofxKinectCommonBridge::initSkeletonStream") << "Cannot configure once the sensor has already started";
		return false;
	}
	KCBGetBodyIndexFrameDescription(hKinect, &bodyIndexFrameDescription);

	bodyIndexPixels.allocate(bodyIndexFrameDescription.width, bodyIndexFrameDescription.width, OF_IMAGE_GRAYSCALE);
	bodyIndexPixelsBack.allocate(bodyIndexFrameDescription.width, bodyIndexFrameDescription.width, OF_IMAGE_GRAYSCALE);

	pBodyIndexFrame = new KCBBodyIndexFrame();
	pBodyIndexFrame->Buffer = bodyIndexPixelsBack.getPixels();
	pBodyIndexFrame->Size = bodyIndexFrameDescription.lengthInPixels;

	bodyIndexTex.allocate(bodyIndexFrameDescription.width, bodyIndexFrameDescription.width, GL_LUMINANCE);
	ofLogError("ofxKinectCommonBridge::initSkeletonStream") << "cannot initialize stream";

	bUsingBodyIndex = true;

	return true; //??
}

bool ofxKinectCommonBridge::initSkeletonStream( bool seated )
{
	if(bStarted){
		ofLogError("ofxKinectCommonBridge::initSkeletonStream") << "Cannot configure once the sensor has already started";
		return false;
	}

	skeletons.resize(6);

	//HRESULT hr = KCBCreateBodyFrame(&pBodyFrame);
	//if (hr >= 0){
		bUsingSkeletons = true;
		return true;
	//}
	//ofLogError("ofxKinectCommonBridge::initSkeletonStream") << "cannot initialize stream";
	//return false;
}

//----------------------------------------------------------
bool ofxKinectCommonBridge::start()
{
	
	startThread(true, false);
	bStarted = true;	
	return true;
}

//----------------------------------------------------------
void ofxKinectCommonBridge::stop() {
	if(bStarted){
		waitForThread(true);
		bStarted = false;

		KCBCloseSensor(&hKinect);

		//delete pBodies; //KCBReleaseBodyFrame(&pBodyFrame);
		KCBReleaseBodyIndexFrame(&pBodyIndexFrame);
		KCBReleaseColorFrame(&pColorFrame);
		KCBReleaseDepthFrame(&pDepthFrame);
		KCBReleaseInfraredFrame(&pInfraredFrame);
		//KCBReleaseLongExposureInfraredFrame(_Inout_ KCBLongExposureInfraredFrame** pLongExposureInfraredFrame);

	}
}	

//----------------------------------------------------------
void ofxKinectCommonBridge::threadedFunction(){

	LONGLONG timestamp;
	
	//how can we tell?
	while(isThreadRunning()) {

		// KCBAllFramesReady
		if (KCBIsFrameReady(hKinect, FrameSourceTypes_Depth) && (SUCCEEDED(KCBGetDepthFrame(hKinect, pDepthFrame) == 0)))
		{
			bNeedsUpdateDepth = true;
        }

		if(bVideoIsInfrared)
		{
			if (KCBIsFrameReady(hKinect, FrameSourceTypes_Infrared) && SUCCEEDED(KCBGetInfraredFrame(hKinect, pInfraredFrame)))
			{
				bNeedsUpdateVideo = true;
				// do we need to do this anymore?
				for (int i = 0; i <colorFrameDescription.width * colorFrameDescription.height; i++)
				{
					videoPixels.getPixels()[i] = reinterpret_cast<USHORT*>(irPixelByteArray)[i] >> 8;
				}
			}
		}
		else
		{
			if (KCBIsFrameReady(hKinect, FrameSourceTypes_Color) && (SUCCEEDED(KCBGetColorFrame	(hKinect, pColorFrame)) == 0))
			{
				bNeedsUpdateVideo = true;
			}
		}

		if(bUsingSkeletons) 
		{
			LONGLONG timestamp;
			IBodyFrame* pBodyFrame = NULL;
			IBody* ppBodies[BODY_COUNT] = { 0 };
			if (SUCCEEDED(KCBGetIBodyFrame(hKinect, &pBodyFrame)))
			{
				/*pBodyFrame->Bodies*/
				HRESULT hr = pBodyFrame->GetAndRefreshBodyData(_countof(ppBodies), ppBodies);
				bNeedsUpdateSkeleton = true;


				// clear everything out
				for (int i = 0; i < 6; i++)
				{
					//skeletonBackBuffer[i].clear();
				}

				// buffer for later
				for (int i = 0; i < _countof(ppBodies); ++i)
				{
					IBody *pBody = ppBodies[i];
					BOOLEAN isTracked = false;
					
					if (pBody == NULL)
					{
						continue;
					}

					HRESULT hr = pBody->get_IsTracked(&isTracked);

					if (isTracked)
					{
						Joint joints[JointType_Count];
						HRESULT hr = ppBodies[i]->GetJoints(_countof(joints), joints);

						JointOrientation jointOrients[JointType_Count];
						hr = ppBodies[i]->GetJointOrientations(_countof(jointOrients), jointOrients);
						if (SUCCEEDED(hr))
						{
							for (int j = 0; j < _countof(joints); ++j)
							{

								/*Kv2JointBackBuffer bb;
								bb.kcbJoint = joints[j];
								bb.kcbOrientation = jointOrients[j];
								bb.type = joints[j].JointType;
								bb.trackingState = joints[j].TrackingState;

								skeletonBackBuffer[i].push_back(bb);*/
							}
						}
					}
					pBody->Release();//ppBodies[i]->Release();
				}

				// all done clean up
				pBodyFrame->Release();
			}
		}

		if (bUsingBodyIndex)
		{
			
			if (KCBIsFrameReady(hKinect, FrameSourceTypes_BodyIndex) && (SUCCEEDED(KCBGetBodyIndexFrame(hKinect, pBodyIndexFrame)) == 0))
			{
				bNeedsUpdateBodyIndex = true;
			}
		}

		//TODO: TILT
		//TODO: ACCEL
		//TODO: FACE
		//TODO: AUDIO
		ofSleepMillis(10);
	}
}
