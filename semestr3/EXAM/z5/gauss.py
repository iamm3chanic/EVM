# copied from stackoverflow
# https://ru.stackoverflow.com/questions/1150851/%D0%BC%D0%B5%D1%82%D0%BE%D0%B4-%D0%B3%D0%B0%D1%83%D1%81%D1%81%D0%B0-%D0%BD%D0%B0-python-3
'''Написать на языке Python функцию, реализующую метод Гаусса решения системы линейных уравнений. 
Матрицу задавать как словарь, индексированный кортежами. Протестировать написанную функцию.'''
myA=[
 [1.0, -2.0, 3.0, -4.0],
 [3.0, 3.0, -5.0, -1.0],
 [3.0, 0.0, 3.0, -10.0],
 [-2.0, 1.0, 2.0, -3.0]
]

myB = [
 2.0,
 -3.0,
 8.0,
 5.0]
# --- end of исходные данные

# --- вывод системы на экран
def FancyPrint(A, B, selected):
    for row in range(len(B)):
        print("(", end='')
        for col in range(len(A[row])):
             print("\t{1:10.2f}{0}".format(" " if (selected is None
or selected != (row, col)) else "*", A[row][col]), end='')
        print("\t) * (\tX{0}) = (\t{1:10.2f})".format(row + 1, B[row]))
# --- end of вывод системы на экран

# --- перемена местами двух строк системы
def SwapRows(A, B, row1, row2):
    A[row1], A[row2] = A[row2], A[row1]
    B[row1], B[row2] = B[row2], B[row1]
# --- end of перемена местами двух строк системы

# --- деление строки системы на число
def DivideRow(A, B, row, divider):
    A[row] = [a / divider for a in A[row]]
    B[row] /= divider
# --- end of деление строки системы на число

# --- сложение строки системы с другой строкой, умноженной на число
def CombineRows(A, B, row, source_row, weight):
    A[row] = [(a + k * weight) for a, k in zip(A[row], A[source_row])]
    B[row] += B[source_row] * weight
# --- end of сложение строки системы с другой строкой, умноженной начисло

# --- решение системы методом Гаусса (приведением к треугольному виду)
def Gauss(A, B):
    column = 0
    while (column < len(B)):
        print("Ищем максимальный по модулю элемент в {0}-м столбце:".format(column + 1))
        current_row = None
        for r in range(column, len(A)):
            if current_row is None or abs(A[r][column]) > abs(A[current_row][column]):
                 current_row = r
        if current_row is None:
            print("решений нет")
            return None
        FancyPrint(A, B, (current_row, column))
        if current_row != column:
            print("Переставляем строку с найденным элементом повыше:")
            SwapRows(A, B, current_row, column)
            FancyPrint(A, B, (column, column))
        print("Нормализуем строку с найденным элементом:")
        DivideRow(A, B, column, A[column][column])
        FancyPrint(A, B, (column, column))
        print("Обрабатываем нижележащие строки:")
        for r in range(column + 1, len(A)):
            CombineRows(A, B, r, column, -A[r][column])
        FancyPrint(A, B, (column, column))
        column += 1
    print("Матрица приведена к треугольному виду, считаем решение")
    X = [0 for b in B]
    for i in range(len(B) - 1, -1, -1):
        X[i] = B[i] - sum(x * a for x, a in zip(X[(i + 1):], A[i][(i + 1):]))
    print("Получили ответ:")
    print("\n".join("X{0} =\t{1:10.2f}".format(i + 1, x) for i, x in
enumerate(X)))
    return X
# --- end of решение системы методом Гаусса (приведением к треугольному виду)
print("Исходная система:")
FancyPrint(myA, myB, None)
print("Решаем:")
Gauss(myA, myB)
