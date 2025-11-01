class Producto:
    def __init__(self, nombre, precio, stock):
        self.nombre = nombre
        self.precio = precio
        self.stock = stock


class ItemCarrito:
    def __init__(self, producto, cantidad):
        self.producto = producto
        self.cantidad = cantidad


class CarritoCompras:
    def __init__(self):
        self.items = []

    def agregar_producto(self, producto, cantidad):
        if producto.stock >= cantidad:
            self.items.append(ItemCarrito(producto, cantidad))
            producto.stock -= cantidad
        else:
            print("No hay suficiente stock.")

    def eliminar_producto(self, nombre):
        for item in self.items:
            if item.producto.nombre == nombre:
                item.producto.stock += item.cantidad
                self.items.remove(item)
                break

    def total(self):
        total = 0
        for item in self.items:
            total += item.producto.precio * item.cantidad
        return total


class Usuario:
    def __init__(self, nombre):
        self.nombre = nombre
        self.historial = []

    def comprar(self, carrito):
        if carrito.items:
            self.historial.append(carrito)
            print(f"Compra realizada por ${carrito.total()}")
        else:
            print("El carrito está vacío.")


# Ejemplo de uso
p1 = Producto("Camisa", 30000, 10)
p2 = Producto("Pantalón", 50000, 5)

carrito = CarritoCompras()
carrito.agregar_producto(p1, 2)
carrito.agregar_producto(p2, 1)

print("Total a pagar:", carrito.total())

usuario = Usuario("Sara")
usuario.comprar(carrito)
