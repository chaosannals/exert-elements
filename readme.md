# elements

## 布局

```c++
fixed_size({ width, height }, subject);//固定大小
hsize(width, subject); // 横向大小
vsize(height, subject); // 纵向大小
min_size({ width, height }, subject); // 最小限制
hmin_size(width, subject); // 最小横向
vmin_size(height, subject); // 最小纵向
max_size({ width, height }, subject); // 最大限制
hmax_size(width, subject); // 最大横向
vmax_size(height, subject); // 最小纵向

htile(e1,...eN); // 列 固定
htile_composite c; // 列 动态 可通过 push_back 添加。
c.push_back(share(child));

vtile(e1,...eN); // 行 固定
vtile_composite c; // 行 动态 可通过 push_back 添加。
c.push_back(share(child));

// 配合 htile 和 vtile 行列布局使用。
// stretch 是比例参数，汇总 行列 总数后 按比例延展
// 类似前端 flex 但是目前看有些问题，和部分布局器结合后会导致布局器没有效果。
hstretch(stretch, subject);// 横向延展
vstretch(stretch, subject);// 竖向延展

scale(scale, subject);// 缩放，这个是放大倍数。原组件大小立意不清，缩放应该会有很多种奇怪的问题。

halign(align, subject);//横向对齐，align 居然是浮点数，这样对齐又会有很多不清的问题。
// 除了以下 3个值，其他值的表现可能会很差。
halign(0.0, subject); // 左对齐
halign(1.0, subject); // 右对齐
halign(0.5, subject); // 横向居中

align_left(subject); // 左对齐
align_center(subject); // 横向居中
align_right(subject); // 右对齐

valign(align, subject); // 纵向对齐，align 居然是浮点数。
align_top(subject); // 顶部对齐
align_middle(subject);// 纵向居中
align_bottom(subject);// 底部对齐

// 这种复合的很怪，一般对齐采用 行列布局嵌套。
// 这个应该是在 layer 这种自由布局里面使用。
align_left_top(subject); // 左上角
align_center_top(subject); // 顶部居中
align_right_top(subject); // 右上角
align_left_middle(subject); // 左居中
align_center_middle(subject); // 居中
align_right_middle(subject); // 右居中
align_left_bottom(subject); // 左下角
align_center_bottom(subject); // 底部居中
align_right_bottom(subject); // 右下角

margin({ left, top, right, bottom }, subject); // 外边距
left_margin(left, subject); // 左外边距
right_margin(right, subject); // 右外边距
top_margin(top, subject); // 上外边距
bottom_margin(bottom, subject); // 下外边距
// 以下写法均是 横向外边距，居然无端增加复杂度。
hmargin({ left, right }, subject);
hmargin(left, right, subject);
left_right_margin({ left, right }, subject);
left_right_margin(left, right, subject);
// 一下写法均是 纵向外边距。
vmargin({ top, bottom }, subject);
vmargin(top, bottom, subject);
top_bottom_margin({ top, bottom }, subject);
top_bottom_margin(top, bottom, subject);
// 左上外边距
left_top_margin({ left, top }, subject);
left_top_margin(left, top, subject);
// 左下外边距
left_bottom_margin({ left, bottom }, subject);
left_bottom_margin(left, bottom, subject);
// 右上外边距
right_top_margin({ right, top }, subject);
right_top_margin(right, top, subject);
// 右下外边距
right_bottom_margin({ right, bottom }, subject);
right_bottom_margin(right, bottom, subject);

// 相对布局 类似前端：position: absolute, 通过 上下左右定位。
floating({ left, top, right, bottom }, subject);

// 这东西和 htile 混合 stretch 很相似，功能还差。
// 横向网格布局 v1到vN 比例系数， e1 到 eN 是元素
hgrid({v1,...vN}, e1,...eN); // 固定列，初始化时固定。
// 动态列，可以通过 push_back 添加。
hgrid_composite c{v1,...vN};
c.push_back(share(child));

// 这东西和 vtile 混合 stretch 很相似，功能还差。
// 纵向网格布局 v1到vN 比例系数， e1 到 eN 是元素
vgrid({v1,...vN}, e1,...eN); // 固定行，初始化时固定。
// 动态行，可以通过 push_back 添加。
vgrid_composite c{ v1,...vN };
c.push_back(share(child));

// 层，类似 Jetpack Compose 的 Box 
// 区别是 先写在前，后写在后。（Box 相反）
layer(e1,...eN); // 固定 元素个数
layer_composite c; // 动态 元素个数，可以通过 push_back 动态添加
c.push_back(share(child));

// 元素组，只显示激活的元素，布局上类似 layer
deck(e1, e2, e3... eN); // 固定个数
deck_composite c; // 动态 个数，通过 push_back 添加
c.push_back(share(child));

// 流式布局
flow_composite c; //
c.push_back(share(child));
```