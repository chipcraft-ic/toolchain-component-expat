#ifndef XmlRole_INCLUDED
#define XmlRole_INCLUDED 1

#include "xmltok.h"

#ifdef __cplusplus
extern "C" {
#endif

enum {
  XML_ROLE_ERROR = -1,
  XML_ROLE_NONE = 0,
  XML_ROLE_DOCTYPE_NAME,
  XML_ROLE_DOCTYPE_SYSTEM_ID,
  XML_ROLE_DOCTYPE_PUBLIC_ID,
  XML_ROLE_DOCTYPE_CLOSE,
  XML_ROLE_GENERAL_ENTITY_NAME,
  XML_ROLE_PARAM_ENTITY_NAME,
  XML_ROLE_ENTITY_VALUE,
  XML_ROLE_ENTITY_SYSTEM_ID,
  XML_ROLE_ENTITY_PUBLIC_ID,
  XML_ROLE_ENTITY_NOTATION_NAME,
  XML_ROLE_NOTATION_NAME,
  XML_ROLE_NOTATION_SYSTEM_ID,
  XML_ROLE_NOTATION_PUBLIC_ID,
  XML_ROLE_ATTRIBUTE_NAME,
  XML_ROLE_ATTRIBUTE_TYPE_CDATA,
  XML_ROLE_ATTRIBUTE_TYPE_ID,
  XML_ROLE_ATTRIBUTE_TYPE_IDREF,
  XML_ROLE_ATTRIBUTE_TYPE_IDREFS,
  XML_ROLE_ATTRIBUTE_TYPE_ENTITY,
  XML_ROLE_ATTRIBUTE_TYPE_ENTITIES,
  XML_ROLE_ATTRIBUTE_TYPE_NMTOKEN,
  XML_ROLE_ATTRIBUTE_TYPE_NMTOKENS,
  XML_ROLE_ATTRIBUTE_ENUM_VALUE,
  XML_ROLE_ATTRIBUTE_NOTATION_VALUE,
  XML_ROLE_ATTLIST_ELEMENT_NAME,
  XML_ROLE_IMPLIED_ATTRIBUTE_VALUE,
  XML_ROLE_REQUIRED_ATTRIBUTE_VALUE,
  XML_ROLE_DEFAULT_ATTRIBUTE_VALUE,
  XML_ROLE_FIXED_ATTRIBUTE_VALUE,
  XML_ROLE_ELEMENT_NAME,
  XML_ROLE_CONTENT_ANY,
  XML_ROLE_CONTENT_EMPTY,
  XML_ROLE_CONTENT_PCDATA,
  XML_ROLE_CONTENT_GROUP_OPEN,
  XML_ROLE_END_GROUP,
  XML_ROLE_END_GROUP_REP,
  XML_ROLE_END_GROUP_OPT,
  XML_ROLE_END_GROUP_PLUS,
  XML_ROLE_GROUP_CHOICE,
  XML_ROLE_GROUP_SEQUENCE,
  XML_ROLE_CONTENT_ELEMENT,
  XML_ROLE_CONTENT_ELEMENT_REP,
  XML_ROLE_CONTENT_ELEMENT_OPT,
  XML_ROLE_CONTENT_ELEMENT_PLUS
};

typedef int PROLOG_HANDLER(struct prolog_state *state,
			   int tok,
			   const char *ptr,
			   const char *end,
			   const ENCODING *enc);

typedef struct prolog_state {
  PROLOG_HANDLER *handler;
  unsigned level;
} PROLOG_STATE;

void XMLTOKAPI XmlPrologStateInit(PROLOG_STATE *);

#define XmlTokenRole(state, tok, ptr, end, enc) \
 (((state)->handler)(state, tok, ptr, end, enc))

#ifdef __cplusplus
}
#endif

#endif /* not XmlRole_INCLUDED */