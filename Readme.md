# Wechat_Dat_Decode

微信图像文件高效解码



## Description

由于微信接收的照片被统一转换成了后缀名为 dat 的文件，一般可能有以下几种格式和文件头：

**Jpg** = "FFD8FF"，**Png**  = "89504E47"，**Tif**  = "49492A00"，**Bmp**  = "424D"。

本仓库转换成加密前文件后统一后缀为 jpg，可能导致部分看图软件无法打开转换后的图像，以及编辑时注意源图像格式不一定是 jpg。



## Usage

**C Version: (Recommend)**

```
> wechat_img_transfer(.exe) xuanzhiyin.dat (114514.dat)
> wechat_img_transfer(.exe) *.dat
```

还可以使用 **拖拽一个或多个 dat 文件** 到程序上的方式运行，但是选中的文件不宜过多，用命令行可以搭配正则表达式处理 **任意数量 dat 文件**。

注意 C语言版本限制每个 dat 文件大小为 **32MB**，但是源照片大小不一定小于 32MB，需要的时候可以更改源码的 buf 大小（在 `wechat_img_transfer.c` 第 7 行），改成自己需要的范围。



**Python Version:**

```
> python wechat_img_transfer.py
```

本仓库里面的 Python 版本已经经过一点点优化，相较其他仓库的脚本在处理大文件的时候性能已经有提升。Python 版本的需要自己填写 code，和需要处理的目录，或者你可以自己魔改源码。code 的填写方法就是用图像的前两个 byte 异或 `0xff` 即可获得。



***无论在 Linux 还是在 Windows，很推荐使用 wechat_img_transfer.c 自行编译程序，因为其效率最高。***

***由于 Python 版相比 C 版本的效率相差甚远，因此没有再继续优化。***

