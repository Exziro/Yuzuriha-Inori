import string
def letter_frequency(s):
   s = s.lower()                      #全部转小写
   l = []
   for i in string.lowercase:
      l.append(s.count(i))            #统计个数
   return l 
   def letter_frequency(s):
   s = s.lower()                      #全部转小写
   l = []
   for i in [chr(x) for x in range(97,123)]:
      l.append(s.count(i))            #统计个数
   return l                           #返回