# -*- coding: utf-8 -*-

import os
import sys

coder = 0xde  # Need to change it by using the image file of top2 bytes HEX_code XOR 0xFF

def imageDecode(f):
    if f[-4:] != ".dat":
        pass

    dat_read = open(f, "rb")
    out = f[:-4] + ".jpg"
    png_write = open(out, "wb")

    buffer = bytearray(dat_read.read())
    # out='P:\\'+fn+".png"
    # out=f + ".jpg"
    png_write.write(bytearray([a ^ coder for a in buffer]))

    dat_read.close()
    png_write.close()

def findFlist(f):
    fsinfo = os.listdir(f)

    for fn in fsinfo:
        temp_path = os.path.join(f, fn)
        if not os.path.isdir(temp_path):
            print('文件路径: {}'.format(temp_path))
            print(fn)
            imageDecode(temp_path)
        else:
            findFlist(temp_path)


if __name__ == "__main__":
    if len(sys.argv) == 1:
        print("运行时请设定转换照片文件夹路径 (注意本工具会把子文件夹内的微信图片一起转换)")
    else:
        findFlist(sys.argv[1])  # Need to fill with folder path
