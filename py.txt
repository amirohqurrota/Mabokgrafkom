class Laptop:
    def __init__(self, merk, harga):
        self.merk = brand
        self.harga = price

    def show(self):
        return 'Merk {}\nHarga {}'.format(self.merk,self.harga)

class Gaming(Laptop):
    def __init__(self, merk, harga, ram):
        super().__init__(merk, harga)
        self.ram = ram
    
    def show(self):
        return 'Merk {}\nHarga {}\nRam {}'.format(self.merk,self.harga,self.ram)

gahar = Gaming(input('Merk :'), input('Harga :'), input('Ram :'))