from PIL import Image
from fpdf import FPDF
import os

# 定义存储图片的目标文件夹
folder_name = 'pep-book-photos'

# 获取所有图片的文件名
files = sorted(os.listdir(folder_name))

# 创建一个新的PDF文档
pdf = FPDF()

# 遍历所有图片文件，将每张图片添加到PDF文档中
for filename in files:
    if '.jpg' not in filename:
        continue
    # 打开图片并获取宽度和高度
    img = Image.open(os.path.join(folder_name, filename))
    width, height = img.size
    # 调整图片大小，使其恰好占据PDF页面的大小
    pdf_w, pdf_h = pdf.w, pdf.h
    if width > height:
        img.thumbnail((pdf_w, pdf_w / width * height))
    else:
        img.thumbnail((pdf_h / height * width, pdf_h))
    # 将图片添加到PDF文档中
    pdf.add_page()
    pdf.image(os.path.join(folder_name, filename), 0, 0, pdf_w, pdf_h)

# 保存PDF文档
pdf.output("pep-book-photos.pdf", "F")