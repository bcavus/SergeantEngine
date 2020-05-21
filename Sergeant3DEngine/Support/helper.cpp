#include "helper.h"

Helper::Helper() {

}

Helper::~Helper() {
	delete this;
}

char* Helper::GetAbsolutePath() {

	char result[MAX_PATH];

	printf(result, GetModuleFileName(NULL, result, MAX_PATH));

	return result;
}