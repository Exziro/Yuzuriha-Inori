import string
def letter_frequency(s):
   s = s.lower()                      #ȫ��תСд
   l = []
   for i in string.lowercase:
      l.append(s.count(i))            #ͳ�Ƹ���
   return l 
   def letter_frequency(s):
   s = s.lower()                      #ȫ��תСд
   l = []
   for i in [chr(x) for x in range(97,123)]:
      l.append(s.count(i))            #ͳ�Ƹ���
   return l                           #����