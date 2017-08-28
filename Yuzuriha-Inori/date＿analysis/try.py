# -*- coding: utf-8 -*-
"""
Created on Sun Aug 27 22:16:49 2017

@author: yixi
"""

import pandas as pd #数据分析
import numpy as np #科学计算
from pandas import Series,DataFrame

data_train = pd.read_csv("/Users/Hanxiaoyang/Titanic_data/Train.csv")
data_train
data_train.info()
