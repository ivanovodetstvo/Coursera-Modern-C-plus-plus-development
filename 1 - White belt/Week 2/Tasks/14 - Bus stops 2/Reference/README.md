Эта задача призвана продемонстрировать, что одни контейнеры могут содержаться в других даже в качестве ключей. В данном случае стоило использовать *map<vector< string >, int>* — словарь, для каждого набора остановок (вектора строк) хранящий номер соответствующего маршрута.