# perf-demo

## Perf安裝方式:
$ sudo apt-get install linux-tools-common

接著輸入 perf list 或 perf top 檢查一下 perf 可不可以使用。

如果出現以下的訊息，表示還漏了些東西。

WARNING: perf not found for kernel 3.16.0-50
You may need to install the following packages for this specific kernel:
    linux-tools-3.16.0-50-generic
    linux-cloud-tools-3.16.0-50-generic
上面的 Kernel 版本可能和你不一樣，根據指示安裝起來即可。

不放心的話可以使用＄ uname -r確認。

$ sudo apt-get install linux-tools-3.16.0-50-generic linux-cloud-tools-3.16.0-50-generic

## Perf權限設定:
$ sudo su

$ sysctl -w kernel.perf_event_paranoid=-1

$ echo 0 > /proc/sys/kernel/kptr_restrict

$ Exit

## Perf執行範例 for array_bad.c:
$ gcc array_bad.c -o array_bad

$ perf stat ./array_bad

如果要使用 perf annotate，需加入 -g3 啟動除錯模式

$ gcc array_bad.c -o array_bad
