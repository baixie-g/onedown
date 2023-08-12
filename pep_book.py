import os
import requests

# 定义存储图片的目标文件夹
folder_name = 'pep-book-photos'
if not os.path.exists(folder_name):
    os.makedirs(folder_name)

# 循环下载每张图片
for i in range(1, 161):
    url = f'https://book.pep.com.cn/1311001301181/files/mobile/{i}.jpg'
    response = requests.get(url)
    if response.status_code == 200:
        with open(f'{folder_name}/{i}.jpg', 'wb') as f:
            f.write(response.content)
        print(f'Downloaded {i}.jpg')
    else:
        print(f'Failed to download {i}.jpg')