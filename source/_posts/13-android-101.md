---
title: 13-android-101
date: 2023-07-27 00:01:08
tags:
---

第三章 UI
3.2 控件
TextView
Button
EditText
ImageView
ProgressBar
AlertDialog
ProgressDialog

3.3 布局
.1 LinearLayout 线性布局
- orientation 方向
- layout_gravity 对齐方式
- layout_weight 比例
.2 RelativeLayout 相对布局
- left top
- center
- bottom leaf
- bottom right
android:layout_above
android:layout_below
android:layout_toLeftOf
.3 FrameLayout
android:layout_gravity
.4 PercentFrameLayout / PercentRelativeLayout

3.4 custom
activity -> setContentView(layout)

1) include layout file
```xml
<include layout="@layout/title" />
```

2) extends Layout class and implement view functionality
```java
public class TitleLayout extends LinearLayout {
  public TitleLayout(Context context, AttributeSet attrs) {
    super(context, attrs);
    LayoutInflater.from(context).inflate(R.layout.title, this);

    Button titleBack = (Button) findViewById(R.id.title_back);
    Button titleEdit = (Buton) findViewById(R.id.title_edit);

    titleBack.setOnClickListener(new OnClickListener() {
      @Override
      public void onClick(View v) {
        ((Activity) getContext()).finish();
      }
    })
  }
}
```
3.5 ListView
```xml
<ListView
  android:id="@+id/list_view"
  android:layout_width="match_parent"
  android:layout_height="match_parent" />
```
1111
```java
ArrayAdapter<String> adapter = new ArrayAdapter<String>(
  MainActivity.this, android.R.layout.simple_list_item_1, data);
ListView listView = (listView)findViewById(R.id.list_view);
listView.setAdaptor(adapter);
```
- Customize ListView

5. broadcast

6. storage

