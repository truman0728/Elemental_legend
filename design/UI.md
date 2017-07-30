
# 需求分析——UI

## 基本场景需求

-------------

### 载入场景（ LoadingScene ）
在该场景提前载入游戏有需要的全部或者部分资源进入内存，以加快用户在游戏时的运行速度。
### 准主场景 （ ViceHomeScene ）
一方面根据当前用户的情况展示一些特殊的模块，另一方面用于展示游戏帮助内容和游戏版本开发信息。
### 主场景 （ HomeScene ）
用于显示当前游戏进度，提供用户调整自己角色特性的方法，提供用户设置游戏系统功能的一些方法。
### 游戏场景 ( GameScene )
用于提供用户游戏玩法，展示游戏动画以及胜利失败结果展示。
### 帮助场景 （ HelpScene ）
提供游戏玩法介绍和游戏玩法导向，提供游戏版本和开发信息。
### 设置场景 ( OptionScene )
提供设置游戏音量等一些红能。

------------

## 详细游戏场景需求

------------

### 载入场景
* 载入场景背景 ：根据游戏进度展示不同的载入场景
* 载入场景进度条模块 ： 包括载入进度条、载入数字进度

### 准主场景
* 准主场景背景：根据游戏中用户选择的特性选择准主场景显示的背景
* 进入主场景按钮
* 进入帮助场景按钮
* 进入设置场景按钮

### 主场景
* 游戏进度地图：上下滑动展示游戏进度
* 进入角色特性选择界面按钮
* 进入游戏设置场景的按钮
* 游戏进度任务点按钮：用于开始游戏任务和展示任务信息

### 游戏场景
* 游戏玩法区域
* 游戏动画区域
* 游戏信息区域
* 暂停按钮（可能会使用手势）
* 游戏结束界面

### 帮助场景 
* 介绍游戏场景每一个模块的功能
* 介绍游戏角色特性
* 开始一次向导游戏

### 设置场景
* 开关游戏背景音乐
* 开关游戏音效
* 开启游戏提示（可能会需要购买）

------------