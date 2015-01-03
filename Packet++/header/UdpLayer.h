#ifndef PACKETPP_UDP_LAYER
#define PACKETPP_UDP_LAYER

#include <Layer.h>

#pragma pack(push,1)
struct udphdr {
	uint16_t portSrc;
	uint16_t portDst;
	uint16_t length;
	uint16_t headerChecksum;
};
#pragma pack(pop)

class UdpLayer : public Layer
{
public:
	UdpLayer(uint8_t* data, size_t dataLen, Layer* prevLayer, Packet* packet) : Layer(data, dataLen, prevLayer, packet) { m_Protocol = UDP; }
	UdpLayer(uint16_t portSrc, uint16_t portDst);

	inline udphdr* getUdpHeader() { return (udphdr*)m_Data; };
	uint16_t calculateChecksum(bool writeResultToPacket);

	// implement abstract methods
	void parseNextLayer();
	inline size_t getHeaderLen() { return sizeof(udphdr); }
	void computeCalculateFields();
	std::string toString();
};


#endif /* PACKETPP_UDP_LAYER */
