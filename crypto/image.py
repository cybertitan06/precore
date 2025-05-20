from PIL import Image

class Picture:

    def open_image(self, filename):
        self.img = Image.open(filename)
        image_data = self.img.tobytes()
        self.alignment = 16 - (len(image_data) % 16)
        return image_data + b"\x00"*self.alignment

    def save_image(self, encrypted_bytes, filename):
        encrypted_bytes = encrypted_bytes[:-self.alignment]

        self.img.frombytes(encrypted_bytes)
        self.img.save(filename)