import cv2
import numpy

img = cv2.imread("image.png")
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
_, thresh = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)
contours, _ = cv2.findContours(thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
biggest = max(contours, key=cv2.contourArea)

x, y, w, h = cv2.boundingRect(biggest)

mask = numpy.zeros(gray.shape, dtype=numpy.uint8)
cv2.drawContours(mask, [biggest], -1, 255, -1)
ys, xs = numpy.where(mask == 255)
cx = int(xs.mean())
cy = int(ys.mean())
print("Center of the largest object:", (cx, cy))

cv2.rectangle(img, (x, y), (x + w, y + h), (0, 0, 255), 2)
cv2.circle(img, (cx, cy), 4, (0, 0, 255), -1)
cv2.imshow("Result", img)
cv2.waitKey(0)
cv2.destroyAllWindows()
cv2.imwrite("result.png", img)
