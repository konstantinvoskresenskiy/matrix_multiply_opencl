<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Matrix Multiply OpenCL - Шаг 2.1</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 40px; line-height: 1.6; }
        .step { background: #f4f4f4; padding: 20px; margin: 20px 0; border-radius: 10px; }
        .completed { border-left: 5px solid #28a745; }
        .current { border-left: 5px solid #007bff; background: #e7f3ff; }
        .pending { border-left: 5px solid #6c757d; opacity: 0.7; }
        .file-structure { background: #2d2d2d; color: #f8f8f2; padding: 15px; border-radius: 5px; font-family: monospace; }
        .command { background: #e9ecef; padding: 10px; border-radius: 5px; font-family: monospace; }
    </style>
</head>
<body>
    <h1>🧮 Matrix Multiplication with OpenCL</h1>
    <h2>Шаг 2.1: Реализация OpenCL Kernel</h2>

    <div class="step completed">
        <h3>✅ Шаг 1: Базовая структура проекта</h3>
        <p>Создана структура репозитория с основными файлами и лицензией</p>
    </div>

    <div class="step current">
        <h3>🎯 Шаг 2.1: Реализация OpenCL Kernel</h3>
        <p><strong>Текущий этап:</strong> Создание ядра умножения матриц на OpenCL</p>
        
        <h4>Созданные файлы:</h4>
        <div class="file-structure">
kernels/<br>
├── matrix/<br>
│   └── <strong>matrix_multiply.cl</strong> 🎯<br>
└── common/<br>
    └── helpers.cl
        </div>

        <h4>Основные особенности kernel:</h4>
        <ul>
            <li>✅ Каждый поток вычисляет один элемент результирующей матрицы</li>
            <li>✅ Проверка границ для безопасности</li>
            <li>✅ Строчный формат хранения матриц (row-major)</li>
            <li>✅ Оптимальное использование глобальной памяти</li>
        </ul>

        <h4>Алгоритм работы:</h4>
        <pre>
Для каждого элемента C[i][j]:
    сумма = 0
    для k от 0 до K-1:
        сумма += A[i][k] * B[k][j]
    C[i][j] = сумма
        </pre>
    </div>

    <div class="step pending">
        <h3>⏳ Шаг 2.2: Базовая структура C++ классов</h3>
        <p>Создание заголовочных файлов и базовой структуры классов</p>
    </div>

    <div class="step pending">
        <h3>⏳ Шаг 2.3: Интеграция OpenCL в C++</h3>
        <p>Реализация взаимодействия между C++ кодом и OpenCL kernel</p>
    </div>

    <div class="step pending">
        <h3>⏳ Шаг 2.4: Тестирование</h3>
        <p>Создание unit-тестов и интеграционных тестов</p>
    </div>

    <h3>🚀 Быстрый старт:</h3>
    <div class="command">
# Клонирование репозитория<br>
git clone https://github.com/your-username/matrix-multiply-opencl<br>
cd matrix-multiply-opencl<br><br>

# Просмотр реализации kernel<br>
cat kernels/matrix/matrix_multiply.cl
    </div>

    <h3>📊 Прогресс реализации:</h3>
    <table border="1" cellpadding="10" style="border-collapse: collapse; width: 100%;">
        <tr>
            <th>Этап</th>
            <th>Статус</th>
            <th>Готовность</th>
        </tr>
        <tr>
            <td>Структура проекта</td>
            <td>✅ Завершено</td>
            <td>100%</td>
        </tr>
        <tr>
            <td>OpenCL Kernel</td>
            <td>🎯 В процессе</td>
            <td>80%</td>
        </tr>
        <tr>
            <td>C++ Классы</td>
            <td>⏳ Ожидает</td>
            <td>0%</td>
        </tr>
        <tr>
            <td>Интеграция</td>
            <td>⏳ Ожидает</td>
            <td>0%</td>
        </tr>
        <tr>
            <td>Тестирование</td>
            <td>⏳ Ожидает</td>
            <td>0%</td>
        </tr>
    </table>

    <hr>
    <div style="text-align: center; color: #6c757d;">
        <p><em>Проект умножения матриц с использованием OpenCL • Шаг 2.1</em></p>
    </div>
</body>
</html>
