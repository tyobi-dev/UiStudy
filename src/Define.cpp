#include "Define.h"

const String Define::DATA_DIR =
#ifdef WEB_APP
U"example/";
#else
U"../example/";
#endif
