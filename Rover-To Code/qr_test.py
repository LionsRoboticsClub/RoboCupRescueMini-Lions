import image, time
import sensor as lionCamera

lionCamera.reset()
lionCamera.set_pixformat(lionCamera.RGB565)
lionCamera.set_framesize(lionCamera.VGA)
lionCamera.set_windowing((240,240))

lionCamera.skip_frames(time = 2000)

clock = time.clock()

while(True):
    clock.tick()
    img = lionCamera.snapshot()

    for code in img.find_qrcodes():
        img.draw_rectangle(code.rect(), color = (0, 0, 255))
        print(code.payload())
