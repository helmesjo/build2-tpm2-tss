#include <stddef.h>
#include <string.h>

#include <tss2/tss2_common.h>
#include <tss2/tss2_tcti.h>
#include <tss2/tss2_tcti_cmd.h>

#undef NDEBUG
#include <assert.h>

/* Exported for symbol lookup, there is no header declaration.
 */
const TSS2_TCTI_INFO* Tss2_Tcti_Info (void);

int main (void)
{
  /* Querying the context size needs no context or TPM, but this TCTI
   * requires a non-NULL configuration string even for the size query.
   */
  size_t n = 0;
  assert (Tss2_Tcti_Cmd_Init (NULL, &n, "") == TSS2_RC_SUCCESS);
  assert (n > 0);

  /* The exported info refers to the same initialization function.
   */
  const TSS2_TCTI_INFO* i = Tss2_Tcti_Info ();
  assert (i != NULL);
  assert (i->name != NULL && strlen (i->name) > 0);
  assert (i->init == Tss2_Tcti_Cmd_Init);

  return 0;
}
