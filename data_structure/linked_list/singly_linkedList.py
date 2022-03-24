from dataclasses import dataclass, asdict, astuple, field
from typing import List


@dataclass  #(frozen=True)
class Node:
    next: int = field(default=None, repr=False)
    data: List = field(
        default_factory=List,
        compare=False,
        repr=True,
    )

    def __post_init__(self):
        pass


@dataclass
class SingleLinkedList:
    head: int = field(default=None)

    def __post_init__(self):
        pass


if __name__ == '__main__':
    node1 = Node(5, ['key', 'value'])
    node2 = Node(5, ['key2', 'value2'])
    print(node1)
    print(node2.data)
