[![Build Status](https://travis-ci.org/BinaryTreesImplementation/AA-tree.svg?branch=master)](https://travis-ci.org/BinaryTreesImplementation/AA-tree) 

# AA-Tree
---
## Краткое описание
АA-дерево (англ. AA-Tree) — структура данных, представляющая собой сбалансированное двоичное дерево поиска, которое является разновидностью красно-черного дерева с дополнительными ограничениями.

АA-дерево названо по первым буквам имени и фамилии изобретателя, Арне Андерссона, который впервые предложил данную модификацию красно-черного дерева в 1993 году.

Свойства АА-дерева:

+ Уровень каждого листа равен 1.
+ Уровень каждого левого ребенка ровно на один меньше, чем у его родителя.
+ Уровень каждого правого ребенка равен или на один меньше, чем у его родителя.
+ Уровень каждого правого внука строго меньше, чем у его прародителя.
+ Каждая вершина с уровнем больше 1 имеет двоих детей.

В AA-дереве разрешены правые ребра, не идущие подряд, и запрещены все левые горизонтальные ребра. Эти более жесткие ограничения , аналогичные ограничениям на красно-черных деревьях, приводят к более простой реализации балансировки AA-дерева.

SKEW - устранение левого горизонтального ребра. Делаем правое вращение, чтобы заменить поддерево, содержащее левую горизонтальную связь, на поддерево, содержащее разрешенную правую горизонтальную связь.

SPLIT -  устранение двух последовательных правых горизонтальных ребер. Делаем левое вращение и увеличиваем уровень, чтобы заменить поддерево, содержащее две или более последовательных правильных горизонтальных связи, на вершину, содержащую два поддерева с меньшим уровнем.

## Реализация
Данное бинарное дерево поиска реализовано на языке программирования С++. 

Методы доступные для использования: 
+ **Insert**
+ **Remove**
+ **Search**
+ **Skew**
+ **Split**

Время работы методов от времени описывается формулами:

+ Search - **O(log N)**
+ Insert - **O(log N)**
+ Remove - **O(log N)**
+ Skew - **O(log N)**
+ Split - **O(log N)**
