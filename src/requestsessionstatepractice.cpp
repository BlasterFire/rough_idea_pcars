#include "requestsessionstatepractice.h"

#include "decodertelemetrydata.h"

namespace pcars {

Request_Session_State_Practice::Request_Session_State_Practice(Request * request)
	: request_{request} {}

bool Request_Session_State_Practice::request(Decoder * decoder) {

	Decoder_Telemetry_Data * tdecoder = dynamic_cast<Decoder_Telemetry_Data *>(decoder);

	if (tdecoder) {

		if (tdecoder->session_state() == Session_State::SESSION_PRACTICE) {
			return true;
		}

		if (request_) {
			return request_->request(decoder);
		}
	}
	return true;
}

}

