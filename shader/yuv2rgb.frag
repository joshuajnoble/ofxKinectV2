#version 150

uniform sampler2D yPlane;
uniform sampler2D rPlane;
uniform sampler2D bPlane;

in vec2 texcoord;

vec4 yuy2_to_rgb(vec4 yuv)
{

    vec4 output;
    //clip(yuv.g == 0.0f ? -1 : 1);

    output.r = clamp(yuv.g + 1.568648f * (yuv.b - 0.501961f), 0.0f, 1.0f);
    output.g = clamp(yuv.g - 0.186593f * (yuv.r - 0.501961f) - 0.466296f * (yuv.b - 0.501961f), 0.0f, 1.0f);
    output.b = clamp(yuv.g + 1.848352f * (yuv.r - 0.501961f), 0.0f, 1.0f);
    output.a = 1.0f;

    return output;
}


void main()
{
	const ivec4 lut = ivec4(2, 1, 0, 3);

     // Compute real plane sizes (4 samples per pixel)
	ivec2 ySize = textureSize(yPlane, 0);
	ivec2 rSize = textureSize(rPlane, 0);
	ivec2 bSize = textureSize(bPlane, 0);
	
	ySize.x <<= 2;
	rSize.x <<= 2;
	bSize.x <<= 2;

	// Positions
	ivec3 yPos = ivec3(texcoord * ySize, 0);
	ivec3 rPos = ivec3(texcoord * rSize, 0);
	ivec3 bPos = ivec3(texcoord * bSize, 0);
	
	// Select sample from pixel
	yPos.z = lut[yPos.x & 3];
	rPos.z = lut[rPos.x & 3];
	bPos.z = lut[bPos.x & 3];

	yPos.x >>= 2;
	rPos.x >>= 2;
	bPos.x >>= 2;

	// Lookup & prepare
	vec3 yCrCb = vec3(
		(texelFetch(yPlane, yPos.xy, 0)[yPos.z] - 0.0625) * 1.1643,
		 texelFetch(rPlane, rPos.xy, 0)[rPos.z] - 0.5,
		 texelFetch(bPlane, bPos.xy, 0)[bPos.z] - 0.5
	);

	// YCrCb -> RGB
	//gl_FragColor = vec4(
	//	yCrCb.x + 1.59580 * yCrCb.y,
	//	yCrCb.x - 0.39173 * yCrCb.z - 0.81290 * yCrCb.y,
	//	yCrCb.x + 2.01700 * yCrCb.z,
	//	1.0 // Alpha
	//);

	gl_FragColor = yuy2_to_rgb(vec4(yCrCb, 1.0));
}