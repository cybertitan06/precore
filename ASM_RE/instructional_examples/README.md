# Instructional Examples

The purpose of these examples are to provide a simple GDB walk through of topics covered in lecture.  

## Compiling Examples

Simply run `./compile.sh <file.arch.asm>`.  [compile.sh](compile.sh) will parse the filename for the intended architecture and produce an appropriate executable with dwarf debugging format included.  

## Walking through examples

Load up each example in gdb:

```bash
gdb 01_mov
```

It is strongly recommended to use [GEF](https://gef.readthedocs.io/en/master/) to provide a more visually intuitive walk through.  There are several context configuration scripts provided in [gef_configs](gef_configs) to help declutter the interface and focus only on the data pertinent to the walk through.  

These configurations can be sourced via initial invocation of `gdb`:

```bash
gdb 01_mov -command=gef_configs/config_source_regs
```

Or via the `gef` CLI:

```
gef> source gef_configs/config_source_regs
```