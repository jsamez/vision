#%%
import cv2
print(cv2.__version__)

import time


start_time = time.time()
face_cascade = cv2.CascadeClassifier('/Images/haarcascade_frontalface_default.xml')
print(face_cascade.empty())  # 파일이 비어있는지 확인
if True:
    img_path = './Images/Audrey.jpg'
    img = cv2.imread(img_path)
    '''
    rows = img.shape[0]
    cols = img.shape[1]
    channels = img.shape[2]
    '''
    rows,cols,channels = img.shape
    factor = cols/rows

    n_cols = 400
    n_rows = int(n_cols*factor)
    img_resized = cv2.resize(img,(n_rows,n_cols))

    face_image = img_resized
    gray_img = cv2.cvtColor(face_image, cv2.COLOR_BGR2GRAY)

    # 얼굴 검출
    faces = face_cascade.detectMultiScale(gray_img, 1.1, 4)

    # 얼굴 주위에 사각형 그리기
    for (x, y, w, h) in faces:
        cv2.rectangle(img_resized, (x, y), (x + w, y + h), (255, 0, 0), 2)



finish_time = time.time()
elapsed_time_ms = (finish_time - start_time)*1000#ms
print(f'Elapsed time : {elapsed_time_ms:.3f} ms')


cv2.imshow('show_img', img_resized)
cv2.waitKey(0)
cv2.destroyAllWindows()
# %%
