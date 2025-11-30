/*
 * OpenCL ядро для умножения матриц
 * Каждый поток вычисляет один элемент результирующей матрицы
 * Матрицы хранятся в строчном формате (row-major)
 */
__kernel void matrix_multiply(
    __global const int* A,
    __global const int* B, 
    __global int* C,
    const int M,
    const int N,
    const int K)
{
    // Получаем глобальные идентификаторы потоков
    const int row = get_global_id(0);  // Индекс строки в C [0..M-1]
    const int col = get_global_id(1);  // Индекс столбца в C [0..N-1]
    
    // Проверка границ матрицы
    if (row >= M || col >= N) {
        return;
    }
    
    // Вычисляем скалярное произведение строки A и столбца B
    int sum = 0;
    for (int k = 0; k < K; k++) {
        sum += A[row * K + k] * B[k * N + col];
    }
    
    // Сохраняем результат в матрицу C
    C[row * N + col] = sum;
}