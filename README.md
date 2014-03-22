#  Metody obliczeniowe -  projekt 3

## Treść zadania (III.1)

Zagadnienie różniczkowe

```
y' = (1 - y)y + x(x^3 + x +2),  y(1) = 2
```

rozwiązać na przedziale `[ 1, 3 ]` metodą Eulera oraz udoskonaloną metodą Eulera, zwaną metodą Heun’a. Wyniki porównać z rozwiązaniem dokładnym `y(x) = x^2 + 1`.

## Metoda Eulera

Dla równania postaci `y' = f(x, y):y_0 = y(t_0)` dla przedziały `[ a, b ]` oraz kroku `h = |a - b| / m` na osi `x`, gdzie `m` jest stałą, rozważmy równanie rekurencyjne:

```
y_k+1 = y_k + h * f(t_k, y_k),    k=0,1,...,m-1
```

gdzie `t_0 = a`, `t_k = t_0 + k * h`, `k = 1,2,...,m`.

#### Przebieg algorytmu
Dla przedziału `[ a, b ]` z krokiem `h =  |b - a| / m` na osi `x` obliczamy kolejne wartości `y_k+1` zgodnie ze wzorem rekurencyjnym.
