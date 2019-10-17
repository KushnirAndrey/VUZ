"""
8.В анкетах сотрудников некоторого учреждения имеются следующие сведения: фамилия, год рождения, должность (мастер, инженер, рабочий и т.д.),
стаж, образование. Вывести фамилии мастеров с высшим образованием и вычислить их средний стаж. Выполнить сортировку списка.
"""
import xlrd
import os

def check_excel_values(values):
    """
    check excel
    :param values:
    :return:
    """
    for value in values:
        #print(value[1])
        try:
            if (value[0].isalpha() and
                (str(int(value[1])).isdigit() and value[1] >= 1900 and value[1] <= 2003) and
                    value[2].isalpha() and
                    (str(int(value[3])).isdigit() and value[3] >=0 and value[3] <= 60) and
                    value[4].isalpha()):
                return 1
            else:
                return
        except (AttributeError, ValueError):
            return


def read_excel(path):
    """
    read data from excel test.xlsx
    :param path:
    :return vals:
    """
    try:
        # open excel
        excel_data = xlrd.open_workbook('test.xlsx')
    except FileNotFoundError:
        print("File {} not found!".format(path))
        return
    # choose active sheet
    sheet = excel_data.sheet_by_index(0)
    # get data
    values = [sheet.row_values(rownum) for rownum in range(sheet.nrows)]
    if check_excel_values(values[1:]):
        return values
    else:
        print("Внимание!\nОшибка в типе значений в Excel таблице!\n"
              "Для корректной работы программы исправьте данные в таблице!")
        return


def get_average(values):
    """
    :param values:
    :return average value:
    """
    sum = 0
    for value in values:
        # v[3] = experience
        try:
            if value[3] < 0:
                print("Значение стажа должно быть больше или равно 0!")
                return None
            sum += value[3]
        except (TypeError, ValueError):
            return None
    return sum/len(values)


def output(values):
    """
    formated output
    :param values:
    :return None:
    """
    if len(values) == 0:
        print('Таких сотрудников не обнаружено')
        return

    print('\nМастера с высшим образованием:\n'
          '-----------------------------')
    list_of_surnames = [val[0].capitalize() for val in values]
    # list of surnames
    list_of_surnames.sort()
    for i, surname in enumerate(list_of_surnames):
        print('{}) {};'.format(i + 1, surname))
    if not get_average(values):
        print("Внимание!\nОшибка в типе значений в Excel таблице!\n"
              "Для корректной работы программы исправьте данные в таблице!")
    else:
        print("Средний стаж работы мастеров: {} года\n"
              "--------------------------------------\n".format("%.1f" % get_average(values)))


def main():
    """
    main function
    :return None:
    """
    answer = 'Y'
    while answer.lower() == 'y':
        path = input("Для начала работы программы введите имя файла--->")
        #print(path)
        if not os.path.exists(path):
            answer = input('Такого файла не существует!\n'
                           'Для повторного ввода нажмите "y"\n'
                           'Для выхода нажмите любую клавишу\n')
            continue
        # data = read_excel("test.xlsx")
        data = read_excel(path)
        list_of_employes = []
        if not data:
            exit(0)
        for val in data:
            if val[2].lower() == 'мастер' and val[4].lower() == 'высшее':
                list_of_employes.append(val)
        output(list_of_employes)
        answer = input('Для обработки еще 1 файла нажмите "y"\nДля выхода нажмите любую клавишу\n')
    print('Работа программы успешно завершена!')


if __name__ == "__main__":
    main()
