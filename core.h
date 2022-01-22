#include <hls_stream.h>

#include <ap_axi_sdata.h>
typedef ap_axiu<8,2,5,6> uint_8_side_channel;

void contrastChange(hls::stream<uint_8_side_channel> &inStream, hls::stream<uint_8_side_channel> &outStream, unsigned char xMin,unsigned char xMax);
