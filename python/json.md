### [json]( https://docs.python.org/2/library/json.html?highlight=json#module-json )

#### dumps
- 序列化
```
json.dumps(obj, skipkeys=False, ensure_ascii=True, check_circular=True, allow_nan=True, cls=None, indent=None, separators=None, encoding="utf-8", default=None, sort_keys=False, **kw)
```

| . |  |
|:---|:---|
| ensure_ascii | 为true时, 将所有非ASCII字符转换成\uXXXX序列 |
| encoding | ... |
| sort_keys |  |
| indent |  |
| skipkeys | 为true时, 跳过不能序列化的值 |

#### dump
- 序列化 + 写文件
```
json.dump(obj, fp, skipkeys=False, ensure_ascii=True, check_circular=True, allow_nan=True, cls=None, indent=None, separators=None, encoding="utf-8", default=None, sort_keys=False, **kw)
```

#### loads
- 反序列化
```
json.loads(s[, encoding[, cls[, object_hook[, parse_float[, parse_int[, parse_constant[, object_pairs_hook[, **kw]]]]]]]])
```

#### load
- 读文件 + 反序列化
```
json.load(fp[, encoding[, cls[, object_hook[, parse_float[, parse_int[, parse_constant[, object_pairs_hook[, **kw]]]]]]]])
```
