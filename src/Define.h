# pragma once
//# define NO_S3D_USING
# include <Siv3D.hpp>

//Webビルドするときにフラグを立てる。
#define WEB_APP 1


class Define final {

public:
	//=============　定数 =================
	enum
	{
		BLOCK_GROUND_TOP_NUM = 5,
		//BLOCK_GROUND_BOTTOM_NUM = 3,
		BLOCK_GROUND_BOTTOM_NUM = 5,

	};


	//リソースのディレクトリ
	const static String DATA_DIR;

};
