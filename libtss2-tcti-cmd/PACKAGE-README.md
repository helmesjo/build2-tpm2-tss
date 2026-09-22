# libtss2-tcti-cmd - TPM2 software stack sub-process command TCTI C library

This is a `build2` package for the
[`tpm2-tss`](https://github.com/tpm2-software/tpm2-tss) C library. It
provides the TPM command transmission interface (TCTI) module that talks to
a TPM simulator or proxy by piping commands and responses through the
standard input and output of a launched sub-process.


## Usage

To start using `libtss2-tcti-cmd` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libtss2-tcti-cmd ^4.2.0
```

Then import the library in your `buildfile`:

```
import libs = libtss2-tcti-cmd%lib{tss2-tcti-cmd}
```


## Importable targets

This package provides the following importable targets:

```
lib{tss2-tcti-cmd}
```

The library is declared in `<tss2/tss2_tcti_cmd.h>`. The TCTI loader
(`libtss2-tctildr`) finds this module by its shared library name at run time.


## Configuration variables

This package provides no configuration variables.
