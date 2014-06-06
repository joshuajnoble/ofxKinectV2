 /* edited josh noble 2014 retaining google copyright for a yuy2 position lookups */

/*
 * Copyright 2009, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#version 150

uniform sampler2D yPlane;
uniform sampler2D rPlane;
uniform sampler2D bPlane;

in vec2 texcoordVarying;
out vec4 color;

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

float getYPixel(vec2 position) {
  position.y = (position.y * 2.0 / 3.0) + (1.0 / 3.0);
  return texture2D(textureSampler, position).x;
}

vec2 mapCommon(vec2 position, float planarOffset) {
  planarOffset += (imageWidth * floor(position.y / 2.0)) / 2.0 +
                  floor((imageWidth - 1.0 - position.x) / 2.0);
  float x = floor(imageWidth - 1.0 - floor(mod(planarOffset, imageWidth)));
  float y = floor(floor(planarOffset / imageWidth));
  return vec2((x + 0.5) / imageWidth, (y + 0.5) / (1.5 * imageHeight));
}

vec2 mapU(vec2 position) {
  float planarOffset = (imageWidth * imageHeight) / 4.0;
  return mapCommon(position, planarOffset);
}

vec2 mapV(vec2 position) {
  return mapCommon(position, 0.0);
}

void main()
{
  	vec2 pixelPosition = vec2(floor(imageWidth * v_texcoord.x), floor(imageHeight * v_texcoord.y));
  	pixelPosition -= vec2(0.5, 0.5);
  	
  	float yChannel = getYPixel(texcoordVarying);
	float uChannel = texture2D(textureSampler, mapU(pixelPosition)).x;
  	float vChannel = texture2D(textureSampler, mapV(pixelPosition)).x;

  	vec4 channels = vec4(yChannel, uChannel, vChannel, 1.0);
	color = yuy2_to_rgb(channels);
}
