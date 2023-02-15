#include <elements.hpp>

using namespace cycfi::elements;

auto constexpr bkd_color = rgba(35, 35, 37, 255);
auto background = box(bkd_color);

auto track = hsize(40, box(colors::black)); // 轨迹
auto thumb = fixed_size(
	{ 40, 40 },
	rbox(colors::white, 10)
); // 滑块
auto funny_slider = fixed_size(
	{ 40, 400 },
	slider(thumb, track)
); // 滚动条

auto blue_rbox = align_center_middle( // fixed_size 不居中
	fixed_size(
		{ 800, 600 },
		vtile( // 行
			vstretch(
				1.0,
				htile( // 列
					fixed_size(
						{ 40, 40 },
						rbox(colors::medium_blue, 10)
					),
					fixed_size(
						{ 40, 40 },
						rbox(colors::medium_blue, 10)
					),
					fixed_size(
						{ 40, 40 },
						rbox(colors::medium_blue, 10)
					),
					fixed_size(
						{ 40, 40 },
						rbox(colors::medium_blue, 10)
					),
					fixed_size(
						{ 40, 40 },
						rbox(colors::medium_blue, 10)
					),
					fixed_size(
						{ 40, 40 },
						rbox(colors::white, 10)
					),

					// 与固定布局一起时，不会撑大父级，导致不显示。
					hstretch(
						2.0,
						rbox(colors::red, 10)
					),
					hstretch(
						4.0,
						rbox(colors::green, 10)
					)
				)
			),
			deck( // 元素组，默认激活第一个元素。
				fixed_size(
					{ 240, 240 },
					rbox(colors::gold, 10)
				),
				fixed_size(
					{ 400, 400 },
					rbox(colors::medium_blue, 10)
				),
				fixed_size(
					{ 400, 400 },
					rbox(colors::yellow, 10)
				)
			),
			vstretch(
				1.0,
				htile(
					hstretch(
						2.0,
						rbox(colors::cyan, 10)
					),
					hstretch(
						4.0,
						rbox(colors::green, 10)
					)
				)
			),
			vstretch(
				2.0,
				layer(
					fixed_size(
						{ 80, 40 }, 
						rbox(colors::medium_blue, 10)
					),
					fixed_size(
						{ 100, 50 },
						rbox(colors::red, 10)
					),
					margin(
						{ 25, 20, 25, 18 },
						fixed_size(
							{ 120, 60 },
							rbox(colors::green, 10)
						)
					)
					/*fixed_size(
						{ 100, 50 },
						label("“文本，不知道这个版本怎么不显示”")
					)*/
				)
			)
		)
	)
);

int main(int argc, char* argv[]) {
	app _app(argc, argv, "customdemo", "custom.demo");
	window _win(_app.name(), window::standard);
	_win.on_close = [&_app]() { _app.stop(); };

	view _view(_win);

	auto b1 = share(button("to d1", 1.0f, colors::blue));
	auto d1 = rbox(colors::light_cyan, 10);
	auto d2 = rbox(colors::gold, 10);
	deck_composite d;
	d.push_back(b1);// 默认是 b1
	d.push_back(share(d1));
	d.push_back(share(d2));
	auto sd = share(d);
	b1->on_click = [=](bool is_clicked) {
		sd->select(1); // 选中 d1
	};

	// 因为固定布局会前向展开，采用克隆。所以这里多个容器 f 来给固定布局展开
	// f 是 std::vector 实例，所以拷贝时候需要给他拷贝共享指针。。不能给直接 share(d)，会被解释为右值，导致进行克隆。。
	deck_composite f;
	f.push_back(sd);

	_view.content(
		floating( // 相对布局 类似前端：position: absolute, 通过 上下左右定位。
			{ 100, 100, 400, 400 },
			f
		),
		htile(
			funny_slider,
			vtile(
				vstretch(
					1.0,
					rbox(colors::red, 10)
				),
				vstretch(
					2.0,
					rbox(colors::green, 10)
				),
				vstretch(
					3.0,
					rbox(colors::blue, 10)
				)
			),
			blue_rbox
		),
		background
	);
	
	d.clear();
	// d 是被复制过去 floating 的，清了也没改变。
	_app.run();
}