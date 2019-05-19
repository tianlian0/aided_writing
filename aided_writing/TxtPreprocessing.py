import os
import re

src_path = r""
dist_path = r""

f = open(src_path, "r", encoding='GB18030', errors='ignore')
text = f.read()
f.close()
text = re.sub(r'([^\u4e00-\u9fa5A-Za-z0-9\，\。\；\：\！])', "", text)

f = open(dist_path, 'w', encoding='GB18030', errors='ignore')
f.write(text)
f.close()