# -*- coding: utf-8 -*-
"""
Created on Wed Jul 26 22:25:35 2017

@author: yixi
"""


import sys
reload(sys)
sys.setdefaultencoding('utf8')


import zipfile
import os
from threading import Thread
import time
#压缩文件的路径
path = r'F:\BaiduNetdiskDownload\驱灵师\驱灵1-43合集.zip'
#password='1234'
 
def pojie_zip(path,password):
 if path[-4:]=='.zip':
  #path = dir+ '\\' +file
  #print path
  zip = zipfile.ZipFile(path, "r",zipfile.zlib.DEFLATED)
  #print zip.namelist()
  try:
   #若解压成功，则返回True,和密码
   zip.extractall(path='F:\\BaiduNetdiskDownload\\驱灵师\\',members=zip.namelist() , pwd=password)
   print ' ----success!,The password is %s' % password
   zip.close()
   return True
  except:
   pass #如果发生异常，不报错
  print 'error'
   
   
def get_pass():
 #密码字典的路径
 passPath='F:\BaiduNetdiskDownload\驱灵师\test.txt'
 passFile=open(passPath,'r')
 for line in passFile.readlines():
  password=line.strip('\n')
  print 'Try the password %s' % password
  if pojie_zip(path,password):
   break
 passFile.close()
if __name__=='__main__':
 start=time.clock()
 get_pass()
 print "done (%.2f seconds)" % (time.clock() - start)