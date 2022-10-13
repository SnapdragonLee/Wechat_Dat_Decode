# -*- coding: utf-8 -*-

import os

out_path = r"./"
coder = 0xde # Need to change it by using the image file of top2 bytes HEX_code XOR 0xFF


def imageDecode(f, fn):

    dat_read = open(f + fn, "rb")
    buffer = bytearray(dat_read.read())

    # out='P:\\'+fn+".png"
    # out=f + ".jpg"
    out = out_path + fn + ".jpg"
    png_write = open(out, "wb")

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
            imageDecode(temp_path, fn)
        else:
            pass

if __name__=="__main__":
    findFlist() # Need to fill with folder path