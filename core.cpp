#include "core.h"


void contrastChange(hls::stream<uint_8_side_channel> &inStream, hls::stream<uint_8_side_channel> &outStream, unsigned char xMin,unsigned char xMax)
{
#pragma HLS INTERFACE s_axilite port=xMin bundle=CRTL_BUS
#pragma HLS INTERFACE s_axilite port=return bundle=CRTL_BUS
#pragma HLS INTERFACE s_axilite port=xMax bundle=CRTL_BUS
#pragma HLS INTERFACE axis port=outStream
#pragma HLS INTERFACE axis port=inStream

	float xMax_minus_xMin = xMax-xMin;

	for (int idxPixel=0; idxPixel < (320*240);idxPixel++)
	{
#pragma HLS PIPELINE
		uint_8_side_channel currPixelSideChannel = inStream.read();
		uint_8_side_channel dataOutSideChannel;
		unsigned char x_t = currPixelSideChannel.data;

		float y_t_float =((x_t -xMin) / (xMax_minus_xMin))*255;

		unsigned char y_t = y_t_float;

		dataOutSideChannel.data =y_t;
		dataOutSideChannel.keep = currPixelSideChannel.keep;
		dataOutSideChannel.strb = currPixelSideChannel.keep;
		dataOutSideChannel.user = currPixelSideChannel.user;
		dataOutSideChannel.last = currPixelSideChannel.last;
		dataOutSideChannel.id = currPixelSideChannel.id;
		dataOutSideChannel.dest = currPixelSideChannel.dest;
		outStream.write(dataOutSideChannel);
	}

}
