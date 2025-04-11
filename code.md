---
layout: page
title: 代码库
permalink: /code/
---

## 源代码浏览

以下是代码库中的文件列表：

{% assign code_files = site.static_files | where_exp: "file", "file.path contains '/src/'" %}
<ul>
{% for file in code_files %}
  <li>
    <a href="{{ file.path | relative_url }}">{{ file.path | remove: "/src/" }}</a>
  </li>
{% endfor %}
</ul>
