import os
import qrcode

img = qrcode.make("https://jareer-portfolio.vercel.app/")

img.save("qr.png", "PNG")