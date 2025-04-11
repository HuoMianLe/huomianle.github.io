---
layout: page
title: 代码库
permalink: /code/
---

## 源代码浏览

以下是代码库中的内容：

{% for file in site.static_files %}
{% if file.path contains '/src/' %}

### {{ file.name }}

{% if file.extname == '.cpp' %}
```cpp
{% include_relative src/{{ file.name }} %}
```
{% endif %}

{% if file.extname == '.py' %}
```python
{% include_relative src/{{ file.name }} %}
```
{% endif %}

{% endif %}
{% endfor %}

<style>
.highlight {
    margin: 20px 0;
    padding: 20px;
    border-radius: 5px;
    background-color: #f6f8fa;
    overflow-x: auto;
}

.highlight pre {
    margin: 0;
    font-family: 'Consolas', 'Monaco', 'Courier New', monospace;
    font-size: 14px;
    line-height: 1.5;
}

h3 {
    margin-top: 40px;
    padding-top: 20px;
    border-top: 1px solid #eaecef;
}

h3:first-of-type {
    border-top: none;
    padding-top: 0;
}
</style>
