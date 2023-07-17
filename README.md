![Type](https://img.shields.io/badge/type-app-orange?style=for-the-badge&logo=cplusplus&logoColor=blue)
![Type](https://img.shields.io/badge/type-library-yellow?style=for-the-badge&logo=cplusplus&logoColor=blue)
![Status](https://img.shields.io/badge/status-WIP-blue.svg?style=for-the-badge)
![C++](https://img.shields.io/badge/C++-17-brightgreen?style=for-the-badge&logo=cplusplus)
![CMake](https://img.shields.io/badge/CMake-3.20-firebrick?style=for-the-badge&logo=cmake)

![Build (Windows)](https://img.shields.io/github/actions/workflow/status/Dev-DAA/OpenIt/build_windows.yml?style=for-the-badge&label=Build%20(Windows))
![Build (Linux)](https://img.shields.io/github/actions/workflow/status/Dev-DAA/OpenIt/build_linux.yml?style=for-the-badge&label=Build%20(Linux))

# OpenIT!

Ремейк игры в жанре "головоломка", изданной в России в 1995 году творческой группой Hazard Dreams для компьютера ZX Spectrum.

## 📃 Rules / Правила игры

Играют двое - *игрока против игрока* или *игрок против компьютера*.

Дано игровое поле размером 8 на 8 клеток. Вначале игры все клетки случайным образом заполнены значениями от 1 до 11 включительно и окрашены в один из двух цветов - зелёный и красный. Для выбора ячеек используется каретка. Управление кареткой устроено так, что один игрок может перемещать каретку только вдоль строки, а другой игрок может перемещать каретку только вдоль столбца.

Игра начинается с нулевого счёта, т.е. каждый игрок имеет 0 очков. В процессе игры счёт игрока может быть не только положительным, но так же нулевым и даже стать отрицательным.

Игроки делают ход по очереди. Игрок выбирает любую неоткрытую ячейку. Выбранная ячейка закрывается, а игроку начисляются баллы, в количестве указанном на ячейке. Причём, при открытии зелёных ячеек счёт игрока увеличивается, а при открытии красных ячеек - уменьшается.

Игра оканчивается в одном из следующих случаев:

* открыты все ячейки на поле;
* игрок не может сделать ход, поскольку в его столбце/строке не осталось неоткрытых ячеек.

Возможны два исхода игры:

* побеждает игрок набравший большее количество баллов;
* ничья (если счёта игроков равны).

<!--
## 🗺️ Roadmap / Дорожная карта

- Разработка библиотеки ядра игры
- Разработка клиента
- Разработка сервера
-->

<!--
## 📚 Documentation / Документация

> Добавьте ссылку на документацию
> 
> Например:
> [Documentation](https://linktodocumentation)
-->

## 🤝 Contributing / Внесение вклада

Вклад всегда приветствуются!

Пожалуйста, соблюдайте [Кодекс Поведения](/docs/CODE_OF_CONDUCT_RU.md) ([Code of Conduct](/docs/CODE_OF_CONDUCT.md)) этого проекта.

## 📃 License / Лицензия

[GPL-3.0](/LICENSE)

## 👨‍💻 Authors / Авторы

- [@idma88](https://github.com/idma88)