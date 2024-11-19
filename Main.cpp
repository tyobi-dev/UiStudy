# include <Siv3D.hpp> // Siv3D v0.6.15
#include "src/Define.h"

class SubWindow
{
	Vec2 m_size;
	Vec2 m_pos;
	Vec2 m_posTo;
	Vec2 m_vel;
	Font m_font;

public:
	SubWindow() :
		m_size(700, 500),
		m_pos(-m_size.x - 100, Scene::Height() / 2 - m_size.y / 2),
		m_posTo(m_pos),
		m_vel(),
		m_font(56, Typeface::Bold)
	{
	}

	void show()
	{
		m_posTo.x = Scene::Width() / 2 - m_size.x / 2;
	}

	void hide()
	{
		m_posTo.x = -m_size.x - 100;
	}

	void update()
	{
		m_pos = Math::SmoothDamp(m_pos, m_posTo, m_vel, 0.1, unspecified, Scene::DeltaTime());
	}

	void draw() const
	{
		const ScopedViewport2D viewport{ m_pos.asPoint(), m_size.asPoint() };

		// ウィンドウ背景、枠
		RectF(m_size)
			.draw(ColorF(0, 0.80))
			.drawFrame(8.0, Palette::Dodgerblue);

		// ウィンドウの内容
		const auto f = m_font(U"サブウィンドウだよ");
		f.drawAt(m_size / 2 + Vec2(4, 4), ColorF(0.6, 0.5));
		f.drawAt(m_size / 2, Palette::White);
	}
};

void Main()
{

	//const int width = 640;
	//const int height = 360;

	//Window::Resize(720, 1280);
	Window::Resize(640, 1200);
	Scene::SetBackground(ColorF(0.95, 0.95, 0.95));

	Font font(40, Typeface::Bold);

	SubWindow wnd;

	while (System::Update())
	{
		ClearPrint();
		Print << U"scene size: " << Scene::Size();
		Print << U"virtualSize: " << Window::GetState().virtualSize;
		Print << U"frameBufferSize: " << Window::GetState().frameBufferSize;


		//Line{ 0, 0, 720, 0 }.draw(4, Palette::Orange);
		//Line{ 0, 1280, 720, 1280 }.draw(4, Palette::Orange);


		Rect{ 0, 96, 640, 360 }.draw(Palette::Skyblue);

		font(U"Spaceキーでサブウィンドウ表示").drawAt(Scene::CenterF(), Palette::Gray);

		if (KeySpace.down())
		{
			wnd.show();
		}
		else if (KeySpace.up())
		{
			wnd.hide();
		}

		wnd.update();
		wnd.draw();

		for (int i = 0; i < 15; i++)
		{
			Line{ 0, i * 48, 720, i * 48 }.draw(2, Palette::Orange);

		}
	}


}
