class Graph:
    def __init__(self, V: int):
        pass

    def V(self) -> int:
        raise NotImplementedError

    def E(self) -> int:
        raise NotImplementedError

    def addEdge(self, v: int, w: int):
        raise NotImplementedError

    def adj(self, v: int) -> list:
        raise NotImplementedError

    def toString(self) -> str:
        raise NotImplementedError
