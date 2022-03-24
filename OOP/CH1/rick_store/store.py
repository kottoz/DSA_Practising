import logging
from typing import Optional
# clist is the best for performance to use if you intend to use single or double linked list it's based on CPython.
# from cllist import sllist as csllist # it needs VS tools, i'm using VS code
# linkedlist comparasion https://xwu64.github.io/2020/08/28/Comparison-of-Python-Linked-List-Modules-llist-pyllist-cllist/
# i will use a built in workaround lin from collections
from collections import deque
logging.basicConfig(filename='logging_file.log',
                    filemode='a',
                    format='%(asctime)s,%(msecs)d %(name)s %(levelname)s %(message)s',
                    datefmt='%H:%M:%S',
                    level=logging.DEBUG)
# Guitar class


class Guitar():
    def __init__(self, serialNumber: str, price: float, builder: str, model: str, typePar: str, backWood: str, topWood: str):

        self.serialNumber: str = serialNumber
        self._price: float = price
        self.builder: str = builder
        self.typePar: str = typePar
        self.model: str = model
        self.backWood: str = backWood
        self.topWood: str = topWood

    def getSerialNumber(self) -> str:
        return self.serialNumber
    
    @property
    def price(self) -> float:
        return self._price
    
    @price.setter
    def price(self, price: float):
        try:
            if price <= 0:
                raise ValueError
            self._price = price
        except ValueError:
            logging.exception(
                "Zero or negative price is invalid input for price")

    def getBuilder(self) -> str:
        return self.builder

    def getTopWood(self) -> str:
        return self.topWood

    def getBackWood(self) -> str:
        return self.backWood


# Inventory class
class Inventory:
    def __init__(self) -> None:
        self.guitars: 'deque' = deque()

    def addGuitar(self, serialNumber: str, price: float, builder: str, model: str, typePar: str, backWood: str, topWood: str):
        # Here is a dependancy
        guitar_to_be_added = Guitar(
            serialNumber, price, builder, model, typePar, backWood, topWood)
        self.guitars.append(guitar_to_be_added)

    def getGuitar(self, serialNumber: str) -> Optional['Guitar']:
        for guitar in self.guitars:
            if serialNumber == guitar.serialNumber:
                return guitar
        return None

    def search(self, given_guitar: 'Guitar') -> Optional["Guitar"]:
        # search in this version compares each parameter on the given guitar to each attribute in different guitars inside the inventory --> too much searching
        # TODO: optimiz speed, to get more efficient code
        # pas throuh all indexed guitars in the inventory
        guitar: 'Guitar'
        for guitar in self.guitars:
            # check if the guitar's builder is not None or Empty and also builder
            
            builder = given_guitar.builder
            if builder is not None and builder != "" and guitar.builder == builder:
                continue
            
            # check if the guitar's type is not None or Empty and also type value itself
            typePar = given_guitar.typePar
            if typePar is not None and typePar != "" and guitar.typePar == typePar:
                continue
            
            # check if the guitar's model is not None or Empty and also builder
            model = given_guitar.model
            if model is not None and model != "" and guitar.model == model:
                continue
            
            # check if the guitar's backWood is not None or Empty and also type value itself
            backWood = given_guitar.backWood
            if backWood is not None and backWood != "" and guitar.backWood == backWood:
                continue

            # check if the guitar's topWood is not None or Empty and also type value itself
            topWood = given_guitar.topWood
            if topWood is not None and topWood != "" and guitar.topWood == topWood:
                continue
        return None
# Test
if __name__ == '__main__':
    
    inv :'Inventory' = Inventory()
    inv.addGuitar(serialNumber="441", price=5.0, builder="builder1", model='model1', typePar='type1', backWood='back1', topWood='top1')
    inv.addGuitar("442", 5, "builder2", 'model2', 'type2', 'back2', 'top2')
    inv.addGuitar("443", 5, "builder3", 'model3', 'type3', 'back3', 'top3')
    inv.addGuitar("444", 5, "builder4", 'model4', 'type4', 'back4', 'top4')
    
    client_g:'Guitar' = Guitar("441", 5, "builder0", 'model1', 'type1', 'back1', 'top1') 
    
    res = inv.search(client_g)
    
    
    print(res)

