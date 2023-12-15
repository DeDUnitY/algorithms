# Определим класс узла бинарного дерева
class Node:
    def __init__(self, value=None):
        self.value = value
        self.left = None
        self.right = None

    @staticmethod
    def build_tree(str):
        str = str.strip()  # Удалить лишние пробелы по краям
        if not str:
            return None

        # Начинаем с пустого корня
        root = Node(None)
        stack = []
        current = root
        current_value = ""

        for char in str:
            if char.isdigit() or char == '-' or char == '.':  # Проверяем, является ли символ числом
                current_value += char
            else:
                if current_value:  # Если была считана цифра, создаем узел и сбрасываем current_value
                    current.value = int(current_value)
                    current_value = ""

                if char == '(':
                    # Двигаемся влево
                    current.left = Node(None)
                    stack.append(current)
                    current = current.left
                elif char == ',':
                    # Переключаемся к родительскому узлу (от левого узла к правому, если есть)
                    if stack:
                        current = stack.pop()
                    current.right = Node(None)
                    current = current.right
                elif char == ')':
                    # Возвращаемся к родительскому узлу
                    if stack:
                        current = stack.pop()

        if current_value:  # Если последний символ строки - число, создаем узел
            current.value = int(current_value)
        return root

    @staticmethod
    def my_print(str, End=" "):
        if str is not None:
            print(str, end=End)

    @staticmethod
    def non_recursive_preorder_traversal(root):
        if root is None:
            return ""

        stack = [root]
        result = ""

        while stack:
            node = stack.pop()
            if not node.value is None:
                result += str(node.value) + " "
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)

        return result.strip()

    @staticmethod
    def preorder_traversal(node):
        if node:
            node.my_print(node.value)
            node.preorder_traversal(node.left)
            node.preorder_traversal(node.right)

    @staticmethod
    def inorder_traversal(node):
        if node:
            node.inorder_traversal(node.left)
            node.my_print(node.value)
            node.inorder_traversal(node.right)

    @staticmethod
    def postorder_traversal(node):
        if node:
            node.postorder_traversal(node.left)
            node.postorder_traversal(node.right)
            node.my_print(node.value)

    @staticmethod
    def printLine(node):
        if node is None:
            return None
        node.my_print(node.value, "")
        if not ((node.left is None) and (node.right is None)):
            print(" (", end="")
        node.printLine(node.left)
        if not ((node.left is None) and (node.right is None)):
            print(", ", end="")
        node.printLine(node.right)
        if not ((node.left is None) and (node.right is None)):
            print(")", end="")

    @staticmethod
    def getMin(node):
        if node is None:
            return None
        if node.left is None:
            return node
        return node.getMin(node.left)

    @staticmethod
    def getMax(node):
        if node is None:
            return None
        if node.right is None:
            return node
        return node.getMax(node.right)

    @staticmethod
    def insert(node, value):
        if node.value is None:
            node.value = value
            return None
        if value < node.value:
            if node.left is None:
                node.left = Node(value)
            else:
                node.insert(node.left, value)
        elif value >= node.value:
            if node.right is None:
                node.right = Node(value)
            else:
                node.insert(node.right, value)

    @staticmethod
    def search(node, value):
        if node is None:
            return None
        if node.value == value:
            return node
        if value < node.value:
            return node.search(node.left, value)
        else:
            return node.search(node.right, value)

    @staticmethod
    def delete(node, value):
        if node is None:
            return None
        elif value < node.value:
            node.left = node.delete(node.left, value)
        elif value > node.value:
            node.right = node.delete(node.right, value)
        else:
            if node.left is None or node.right is None:
                if node.left is None:
                    node = node.right
                else:
                    node = node.left
            else:
                minRight = node.getMin(node.right)
                node.value = minRight.value
                node.right = node.delete(node.right, minRight.value)

        return node


def main():
    input_string = "8 (3 (1, 6 (4,7)), 10 (, 14(13,)))"
    tree = Node.build_tree(input_string)
    while True:
        print("\nWhat do you want to do with tree?")
        print("1) insert")
        print("2) delete")
        print("3) search")
        print("4) print preorder")
        print("5) print inorder")
        print("6) print postorder")
        print("7) print with linear bracket view")
        print("8) print stack preorder")
        print("0) exit")
        event = int(input())
        match event:
            case 1:
                print("input a number to insert")
                num = int(input())
                Node.insert(tree, num)
            case 2:
                print("input a number to delete")
                num = int(input())
                Node.delete(tree, num)
            case 3:
                print("input a number to search")
                num = int(input())
                temp = Node.search(tree, num)
                Node.printLine(temp)
            case 4:
                Node.preorder_traversal(tree)
            case 5:
                Node.inorder_traversal(tree)
            case 6:
                Node.postorder_traversal(tree)
            case 7:
                Node.printLine(tree)
            case 8:
                Node.non_recursive_preorder_traversal(tree)
            case 0:
                break

        Node.printLine(tree)


if __name__ == "__main__":
    main()
