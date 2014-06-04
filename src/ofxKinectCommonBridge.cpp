#include "ofxKinectCommonBridge.h"

// test comment

/*
SkeletonBone::SkeletonBone ( const Vector4& inPosition, const _NUI_SKELETON_BONE_ORIENTATION& orient, const NUI_SKELETON_POSITION_TRACKING_STATE& trackingState) {

	cameraRotation.set( orient.absoluteRotation.rotationMatrix.M11, orient.absoluteRotation.rotationMatrix.M12, orient.absoluteRotation.rotationMatrix.M13, orient.absoluteRotation.rotationMatrix.M14,
		orient.absoluteRotation.rotationMatrix.M21, orient.absoluteRotation.rotationMatrix.M22, orient.absoluteRotation.rotationMatrix.M23, orient.absoluteRotation.rotationMatrix.M24,
		orient.absoluteRotation.rotationMatrix.M31, orient.absoluteRotation.rotationMatrix.M32, orient.absoluteRotation.rotationMatrix.M33, orient.absoluteRotation.rotationMatrix.M34,
		orient.absoluteRotation.rotationMatrix.M41, orient.absoluteRotation.rotationMatrix.M42, orient.absoluteRotation.rotationMatrix.M43, orient.absoluteRotation.rotationMatrix.M44);

	position.set( inPosition.x, inPosition.y, inPosition.z );

	startJoint = orient.startJoint;
	endJoint = orient.endJoint;

	NuiTransformSkeletonToDepthImage(inPosition, &(screenPosition.x), &(screenPosition.y), NUI_IMAGE_RESOLUTION_640x480);

	rotation.set( orient.hierarchicalRotation.rotationMatrix.M11, orient.hierarchicalRotation.rotationMatrix.M12, orient.hierarchicalRotation.rotationMatrix.M13, orient.hierarchicalRotation.rotationMatrix.M14,
		orient.hierarchicalRotation.rotationMatrix.M21, orient.hierarchicalRotation.rotationMatrix.M22, orient.hierarchicalRotation.rotationMatrix.M23, orient.hierarchicalRotation.rotationMatrix.M24,
		orient.hierarchicalRotation.rotationMatrix.M31, orient.hierarchicalRotation.rotationMatrix.M32, orient.hierarchicalRotation.rotationMatrix.M33, orient.hierarchicalRotation.rotationMatrix.M34,
		orient.hierarchicalRotation.rotationMatrix.M41, orient.hierarchicalRotation.rotationMatrix.M42, orient.hierarchicalRotation.rotationMatrix.M43, orient.hierarchicalRotation.rotationMatrix.M44);
	
	switch(trackingState) {
	case NUI_SKELETON_POSITION_NOT_TRACKED:
		this->trackingState = NotTracked;
		break;
	case NUI_SKELETON_POSITION_INFERRED:
		this->trackingState = Inferred;
		break;
	case NUI_SKELETON_POSITION_TRACKED:
		this->trackingState = Tracked;
		break;
	}
}

const ofVec3f& SkeletonBone::getStartPosition() {
	return position;
}

const ofQuaternion&	SkeletonBone::getRotation() {
	return rotation.getRotate();
}

const ofMatrix4x4& SkeletonBone::getRotationMatrix() {
	return rotation;
}

const int SkeletonBone::getStartJoint() {
	return startJoint;
}

const ofQuaternion SkeletonBone::getCameraRotation() {
	return cameraRotation.getRotate();
}

const ofMatrix4x4 SkeletonBone::getCameraRotationMatrix() {
	return rotation;
}

int SkeletonBone::getEndJoint() {
	return endJoint;
}

SkeletonBone::TrackingState SkeletonBone::getTrackingState() {
	return trackingState;
}

const ofVec3f SkeletonBone::getScreenPosition() {
	return screenPosition;
}*/
//
//SkeletonBone::SkeletonBone(const Vector4& inPosition, const JointOrientation& orient ) {
//
//	/*cameraRotation.set(orient.Orientation., orient.absoluteRotation.rotationMatrix.M12, orient.absoluteRotation.rotationMatrix.M13, orient.absoluteRotation.rotationMatrix.M14,
//		orient.absoluteRotation.rotationMatrix.M21, orient.absoluteRotation.rotationMatrix.M22, orient.absoluteRotation.rotationMatrix.M23, orient.absoluteRotation.rotationMatrix.M24,
//		orient.absoluteRotation.rotationMatrix.M31, orient.absoluteRotation.rotationMatrix.M32, orient.absoluteRotation.rotationMatrix.M33, orient.absoluteRotation.rotationMatrix.M34,
//		orient.absoluteRotation.rotationMatrix.M41, orient.absoluteRotation.rotationMatrix.M42, orient.absoluteRotation.rotationMatrix.M43, orient.absoluteRotation.rotationMatrix.M44);*/
//
//	//ofMatrix4x4 rotMat;
//	ofQuaternion quat(orient.Orientation.x, orient.Orientation.y, orient.Orientation.z, orient.Orientation.w);
//	//rotMat.makeRotationMatrix(quat);
//
//	/*startJoint = orient.JointType;
//	endJoint = orient.endJoint;*/
//
//	//NuiTransformSkeletonToDepthImage(inPosition, &(screenPosition.x), &(screenPosition.y), NUI_IMAGE_RESOLUTION_640x480);
//
//	/*rotation.set(orient.hierarchicalRotation.rotationMatrix.M11, orient.hierarchicalRotation.rotationMatrix.M12, orient.hierarchicalRotation.rotationMatrix.M13, orient.hierarchicalRotation.rotationMatrix.M14,
//		orient.hierarchicalRotation.rotationMatrix.M21, orient.hierarchicalRotation.rotationMatrix.M22, orient.hierarchicalRotation.rotationMatrix.M23, orient.hierarchicalRotation.rotationMatrix.M24,
//		orient.hierarchicalRotation.rotationMatrix.M31, orient.hierarchicalRotation.rotationMatrix.M32, orient.hierarchicalRotation.rotationMatrix.M33, orient.hierarchicalRotation.rotationMatrix.M34,
//		orient.hierarchicalRotation.rotationMatrix.M41, orient.hierarchicalRotation.rotationMatrix.M42, orient.hierarchicalRotation.rotationMatrix.M43, orient.hierarchicalRotation.rotationMatrix.M44);*/
//
//	rotation.makeRotationMatrix(quat);
//
//	switch () {
//	case NUI_SKELETON_POSITION_NOT_TRACKED:
//		this->trackingState = NotTracked;
//		break;
//	case NUI_SKELETON_POSITION_INFERRED:
//		this->trackingState = Inferred;
//		break;
//	case NUI_SKELETON_POSITION_TRACKED:
//		this->trackingState = Tracked;
//		break;
//	}
//}
//
//const ofVec3f& SkeletonBone::getStartPosition() {
//	return position;
//}
//
//const ofQuaternion&	SkeletonBone::getRotation() {
//	return rotation.getRotate();
//}
//
//const ofMatrix4x4& SkeletonBone::getRotationMatrix() {
//	return rotation;
//}
//
//const int SkeletonBone::getStartJoint() {
//	return startJoint;
//}
//
//const ofQuaternion SkeletonBone::getCameraRotation() {
//	return cameraRotation.getRotate();
//}
//
//const ofMatrix4x4 SkeletonBone::getCameraRotationMatrix() {
//	return rotation;
//}
//
//int SkeletonBone::getEndJoint() {
//	return endJoint;
//}
//
//SkeletonBone::TrackingState SkeletonBone::getTrackingState() {
//	return trackingState;
//}
//
//const ofVec3f SkeletonBone::getScreenPosition() {
//	return screenPosition;
//}



//================================================================================================================
// common bridge
//================================================================================================================


ofxKinectCommonBridge::ofxKinectCommonBridge(){
	hKinect = NULL;

	pDepthFrame = NULL;
	pColorFrame = NULL;

	beginMappingColorToDepth = false;

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

		//swap(videoPixels,videoPixelsBack);

		// if you're mapping color pix to depth space, downscale color pix
		/*if(mappingColorToDepth && beginMappingColorToDepth)
		{

			NUI_DEPTH_IMAGE_POINT  *pts = new NUI_DEPTH_IMAGE_POINT[K2_COLOR_HEIGHT*K2_COLOR_WIDTH];
			NUI_DEPTH_IMAGE_PIXEL  *depth = new NUI_DEPTH_IMAGE_PIXEL[K2_IR_HEIGHT*K2_IR_WIDTH];

			int i = 0; 
			while ( i < (K2_IR_WIDTH*K2_IR_HEIGHT)) {
				depth[i].depth = (USHORT) depthPixelsRaw.getPixels()[i];
				depth[i].playerIndex = 0;
				i++;
			}

			HRESULT mapResult;
			mapResult = mapper->MapColorFrameToDepthFrame(NUI_IMAGE_TYPE_COLOR, NUI_IMAGE_RESOLUTION_640x480, NUI_IMAGE_RESOLUTION_640x480,
						640 * 480, depth,
						640 * 480, pts);

			for( int i = 0; i < (K2_IR_WIDTH*K2_IR_HEIGHT); i++ )
			{
				videoPixels[i] = videoPixels[pts[i].y * K2_IR_WIDTH + pts[i].x];
			}

			delete[] pts;
			delete[] depth;

		}*/

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
		
		// if mapping depth to color, upscale depth
		/*if(mappingDepthToColor) 
		{
			NUI_COLOR_IMAGE_POINT *pts = new NUI_COLOR_IMAGE_POINT[K2_COLOR_WIDTH * K2_COLOR_HEIGHT];
			NUI_DEPTH_IMAGE_PIXEL * depth = new NUI_DEPTH_IMAGE_PIXEL[(K2_IR_WIDTH * K2_IR_WIDTH)];
			
			int i = 0; 
			while ( i < (K2_IR_WIDTH*K2_IR_HEIGHT)) {
				depth[i].depth = (USHORT) depthPixelsRaw.getPixels()[i];
				depth[i].playerIndex = 0;
				i++;
			}
			
			HRESULT mapResult;
			mapResult = mapper->MapDepthFrameToColorFrame(depthRes, (K2_IR_WIDTH*K2_IR_HEIGHT), depth, NUI_IMAGE_TYPE_COLOR, colorRes, (K2_IR_WIDTH*K2_IR_HEIGHT), pts);

			if(SUCCEEDED(mapResult))
			{

				for( int i = 0; i < (K2_IR_WIDTH*K2_IR_HEIGHT); i++ ) {
					if(pts[i].x > 0 && pts[i].x < K2_IR_WIDTH && pts[i].y > 0 && pts[i].y < K2_IR_HEIGHT) {
						depthPixels[i] = depthLookupTable[ ofClamp(depthPixelsRaw[pts[i].y * K2_IR_WIDTH + pts[i].x] >> 4, 0, depthLookupTable.size()-1 ) ];
					} else {
						depthPixels[i] = 0;
					}
				}
			} else {
				ofLog() << " mapping error " << mapResult << endl;
			}

			delete[] pts;
			delete[] depth;
		
			for(int i = 0; i < depthPixels.getWidth()*depthPixels.getHeight(); i++) {
				depthPixelsRaw[i] = depthPixelsRaw[i] >> 4;
			}

		} else {
*/
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
	//if(bUsingSkeletons && bNeedsUpdateSkeleton)
	//{	

	//	bIsSkeletonFrameNew = true;
	//	bNeedsUpdateSkeleton = false;
	//	bool foundSkeleton = false;

	//	for ( int i = 0; i < NUI_SKELETON_COUNT; i++ ) 
	//	{
	//		skeletons.at( i ).clear();

	//		if (  k4wSkeletons.SkeletonData[ i ].eTrackingState == NUI_SKELETON_TRACKED || k4wSkeletons.SkeletonData[ i ].eTrackingState == NUI_SKELETON_POSITION_ONLY ) {
	//			//cout << " we have a skeleton " << ofGetElapsedTimeMillis() << endl;
	//			_NUI_SKELETON_BONE_ORIENTATION bones[ NUI_SKELETON_POSITION_COUNT ];
	//			if(SUCCEEDED(NuiSkeletonCalculateBoneOrientations( &(k4wSkeletons.SkeletonData[i]), bones ))) {
	//				//error( hr );
	//			}

	//			for ( int j = 0; j < NUI_SKELETON_POSITION_COUNT; j++ ) 
	//			{
	//				SkeletonBone bone( k4wSkeletons.SkeletonData[i].SkeletonPositions[j], bones[j], k4wSkeletons.SkeletonData[i].eSkeletonPositionTrackingState[j] );
	//				skeletons.at(i).insert( std::pair<NUI_SKELETON_POSITION_INDEX, SkeletonBone>( NUI_SKELETON_POSITION_INDEX(j), bone ) );
	//			}
	//			bNeedsUpdateSkeleton = true;
	//		}
	//	}
	//
	//} else {
		bNeedsUpdateSkeleton = false;
	//}
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
//
void ofxKinectCommonBridge::drawSkeleton( int index )
{
	// Iterate through skeletons
	uint32_t i = 0;
	if(index > skeletons.size())
	{
		ofLog() << " skeleton index too high " << endl;
		return;
	}

	ofVec3f lastPosition(-1,-1,-1);

	// Iterate through joints
	for ( Skeleton::iterator it = skeletons.at(index).begin(); it != skeletons.at(index).end(); ++it ) 
	{

		// Get position and rotation
		Joint joint = it->second;

		ofSetColor(255, 255, 255);
		ofSetLineWidth(3.0); // fat lines
		//int startJoint = joint.getStartJoint();
		//// do we have a start joint?
		if ( lastPosition.z != -1 ) // this is dum 
		{
			// draw the line
			ofLine(lastPosition, ofVec3f(joint.Position.X, joint.Position.Y, joint.Position.Z));
		}

		//ofSetColor(255, 0, 0);
		//// Draw joint
		//ofCircle( bone.getScreenPosition(), 10 );

		ofSetColor(255, 0, 0);
		ofCircle(ofVec3f(joint.Position.X, joint.Position.Y, joint.Position.Z), 10);

		lastPosition.set(joint.Position.X, joint.Position.Y, joint.Position.Z);
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

bool ofxKinectCommonBridge::initDepthStream( int width, int height, bool nearMode, bool mapDepthToColor )
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

bool ofxKinectCommonBridge::initColorStream( int width, int height, bool mapColorToDepth )
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

	pInfraredFrame = new KCBInfraredFrame();
	pInfraredFrame->Buffer = new UINT16[irFrameDescription.lengthInPixels];
	pInfraredFrame->Size = irFrameDescription.lengthInPixels;

	videoPixels.allocate(irFrameDescription.width, irFrameDescription.height, OF_IMAGE_GRAYSCALE);
	videoPixelsBack.allocate(irFrameDescription.width, irFrameDescription.height, OF_IMAGE_GRAYSCALE);

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

	KCBCreateInfraredFrame(irFrameDescription, &pInfraredFrame);
	bInited = true;
	return true;
}

bool ofxKinectCommonBridge::initSkeletonStream( bool seated )
{
	if(bStarted){
		ofLogError("ofxKinectCommonBridge::initSkeletonStream") << "Cannot configure once the sensor has already started";
		return false;
	}

	KCBCreateBodyFrame(&pBodyFrame);

	ofLogError("ofxKinectCommonBridge::initSkeletonStream") << "cannot initialize stream";
	return false;
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

		KCBReleaseBodyFrame(&pBodyFrame);
		KCBReleaseBodyIndexFrame(&pBodyIndexFrame);
		KCBReleaseColorFrame(&pColorFrame);
		KCBReleaseDepthFrame(&pDepthFrame);
		KCBReleaseInfraredFrame(&pInfraredFrame);
		//KCBReleaseLongExposureInfraredFrame(_Inout_ KCBLongExposureInfraredFrame** pLongExposureInfraredFrame);

		//// release these interfaces when done
		//if (mapper)
		//{
		//	mapper->Release();
		//	mapper = nullptr;
		//}
		//if (nuiSensor)
		//{
		//	nuiSensor->Release();
		//	nuiSensor = nullptr;
		//}

	}
}	

//----------------------------------------------------------
void ofxKinectCommonBridge::threadedFunction(){

	LONGLONG timestamp;
	
	cout << "STARTING THREAD" << endl;

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
					videoPixelsBack.getPixels()[i] = reinterpret_cast<USHORT*>(irPixelByteArray)[i] >> 8;
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

		if(bUsingSkeletons) {
			if (KCBIsFrameReady(hKinect, FrameSourceTypes_Body) && SUCCEEDED(KCBGetBodyFrame(hKinect, pBodyFrame)))
			{
				bNeedsUpdateSkeleton = true;
			}
		}

		//TODO: TILT
		//TODO: ACCEL
		//TODO: FACE
		//TODO: AUDIO
		ofSleepMillis(10);
	}
}
