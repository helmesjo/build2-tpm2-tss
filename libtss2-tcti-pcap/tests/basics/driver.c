#include <stddef.h>
#include <string.h>

#include <tss2/tss2_common.h>
#include <tss2/tss2_tcti.h>
#include <tss2/tss2_tcti_pcap.h>

#undef NDEBUG
#include <assert.h>

/* Exported for symbol lookup, there is no header declaration.
 */
const TSS2_TCTI_INFO* Tss2_Tcti_Info (void);

int main (void)
{
  /* Querying the context size needs neither a context nor a TPM.
   */
  size_t n = 0;
  assert (Tss2_Tcti_Pcap_Init (NULL, &n, NULL) == TSS2_RC_SUCCESS);
  assert (n > 0);

  /* The exported info refers to the same initialization function.
   */
  const TSS2_TCTI_INFO* i = Tss2_Tcti_Info ();
  assert (i != NULL);
  assert (i->name != NULL && strlen (i->name) > 0);
  assert (i->init == Tss2_Tcti_Pcap_Init);

  return 0;
}
