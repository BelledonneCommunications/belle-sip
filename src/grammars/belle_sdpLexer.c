/*
 * Copyright (c) 2012-2019 Belledonne Communications SARL.
 *
 * This file is part of belle-sip.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
// [The "BSD license"]
// Copyright (c) 2005-2009 Jim Idle, Temporal Wave LLC
// http://www.temporal-wave.com
// http://www.linkedin.com/in/jimidle
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


/* =============================================================================
 * This is what the grammar programmer asked us to put at the top of every file.
 */

/*
    belle-sip - SIP (RFC3261) library.
    Copyright (C) 2010  Belledonne Communications SARL

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma GCC diagnostic ignored "-Wparentheses"
#pragma GCC diagnostic ignored "-Wunused"
#ifdef __clang__
#pragma GCC diagnostic ignored "-Wtautological-compare"
#endif
#ifndef __clang__
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif

/* End of Header action.
 * =============================================================================
 */

/* -----------------------------------------
 * Include the ANTLR3 generated header file.
 */
#include    "belle_sdpLexer.h"
/* ----------------------------------------- */





/* MACROS that hide the C interface implementations from the
 * generated code, which makes it a little more understandable to the human eye.
 * I am very much against using C pre-processor macros for function calls and bits
 * of code as you cannot see what is happening when single stepping in debuggers
 * and so on. The exception (in my book at least) is for generated code, where you are
 * not maintaining it, but may wish to read and understand it. If you single step it, you know that input()
 * hides some indirect calls, but is always referring to the input stream. This is
 * probably more readable than ctx->input->istream->input(snarfle0->blarg) and allows me to rejig
 * the runtime interfaces without changing the generated code too often, without
 * confusing the reader of the generated output, who may not wish to know the gory
 * details of the interface inheritance.
 */

#define		CTX	ctx

/* Aids in accessing scopes for grammar programmers
 */
#undef	SCOPE_TYPE
#undef	SCOPE_STACK
#undef	SCOPE_TOP
#define	SCOPE_TYPE(scope)   pbelle_sdpLexer_##scope##_SCOPE
#define SCOPE_STACK(scope)  pbelle_sdpLexer_##scope##Stack
#define	SCOPE_TOP(scope)    ctx->pbelle_sdpLexer_##scope##Top
#define	SCOPE_SIZE(scope)		ctx->pbelle_sdpLexer_##scope##Stack_limit
#define SCOPE_INSTANCE(scope, i)	(ctx->SCOPE_STACK(scope)->get(ctx->SCOPE_STACK(scope),i))


/* Macros for accessing things in a lexer
 */
#undef	    LEXER
#undef	    RECOGNIZER
#undef	    RULEMEMO
#undef	    GETCHARINDEX
#undef	    GETLINE
#undef	    GETCHARPOSITIONINLINE
#undef	    EMIT
#undef	    EMITNEW
#undef	    MATCHC
#undef	    MATCHS
#undef	    MATCHRANGE
#undef	    LTOKEN
#undef	    HASFAILED
#undef	    FAILEDFLAG
#undef	    INPUT
#undef	    STRSTREAM
#undef	    LA
#undef	    HASEXCEPTION
#undef	    EXCEPTION
#undef	    CONSTRUCTEX
#undef	    CONSUME
#undef	    LRECOVER
#undef	    MARK
#undef	    REWIND
#undef	    REWINDLAST
#undef	    BACKTRACKING
#undef		MATCHANY
#undef		MEMOIZE
#undef		HAVEPARSEDRULE
#undef		GETTEXT
#undef		INDEX
#undef		SEEK
#undef		PUSHSTREAM
#undef		POPSTREAM
#undef		SETTEXT
#undef		SETTEXT8

#define	    LEXER					ctx->pLexer
#define	    RECOGNIZER			    LEXER->rec
#define		LEXSTATE				RECOGNIZER->state
#define		TOKSOURCE				LEXSTATE->tokSource
#define	    GETCHARINDEX()			LEXER->getCharIndex(LEXER)
#define	    GETLINE()				LEXER->getLine(LEXER)
#define	    GETTEXT()				LEXER->getText(LEXER)
#define	    GETCHARPOSITIONINLINE() LEXER->getCharPositionInLine(LEXER)
#define	    EMIT()					LEXSTATE->type = _type; LEXER->emit(LEXER)
#define	    EMITNEW(t)				LEXER->emitNew(LEXER, t)
#define	    MATCHC(c)				LEXER->matchc(LEXER, c)
#define	    MATCHS(s)				LEXER->matchs(LEXER, s)
#define	    MATCHRANGE(c1,c2)	    LEXER->matchRange(LEXER, c1, c2)
#define	    MATCHANY()				LEXER->matchAny(LEXER)
#define	    LTOKEN  				LEXSTATE->token
#define	    HASFAILED()				(LEXSTATE->failed == ANTLR3_TRUE)
#define	    BACKTRACKING			LEXSTATE->backtracking
#define	    FAILEDFLAG				LEXSTATE->failed
#define	    INPUT					LEXER->input
#define	    STRSTREAM				INPUT
#define		ISTREAM					INPUT->istream
#define		INDEX()					ISTREAM->index(ISTREAM)
#define		SEEK(n)					ISTREAM->seek(ISTREAM, n)
#define	    EOF_TOKEN				&(LEXSTATE->tokSource->eofToken)
#define	    HASEXCEPTION()			(LEXSTATE->error == ANTLR3_TRUE)
#define	    EXCEPTION				LEXSTATE->exception
#define	    CONSTRUCTEX()			RECOGNIZER->exConstruct(RECOGNIZER)
#define	    LRECOVER()				LEXER->recover(LEXER)
#define	    MARK()					ISTREAM->mark(ISTREAM)
#define	    REWIND(m)				ISTREAM->rewind(ISTREAM, m)
#define	    REWINDLAST()			ISTREAM->rewindLast(ISTREAM)
#define		MEMOIZE(ri,si)			RECOGNIZER->memoize(RECOGNIZER, ri, si)
#define		HAVEPARSEDRULE(r)		RECOGNIZER->alreadyParsedRule(RECOGNIZER, r)
#define		PUSHSTREAM(str)			LEXER->pushCharStream(LEXER, str)
#define		POPSTREAM()				LEXER->popCharStream(LEXER)
#define		SETTEXT(str)			LEXSTATE->text = str
#define		SKIP()					LEXSTATE->token = &(TOKSOURCE->skipToken)
#define		USER1					LEXSTATE->user1
#define		USER2					LEXSTATE->user2
#define		USER3					LEXSTATE->user3
#define		CUSTOM					LEXSTATE->custom
#define		RULEMEMO				LEXSTATE->ruleMemo
#define		DBG						RECOGNIZER->debugger

/* If we have been told we can rely on the standard 8 bit or UTF16 input
 * stream, then we can define our macros to use the direct pointers
 * in the input object, which is much faster than indirect calls. This
 * is really only significant to lexers with a lot of fragment rules (which
 * do not place LA(1) in a temporary at the moment) and even then
 * only if there is a lot of input (order of say 1M or so).
 */
#if	defined(ANTLR3_INLINE_INPUT_8BIT) || defined(ANTLR3_INLINE_INPUT_UTF16)

# ifdef	ANTLR3_INLINE_INPUT_8BIT

/* 8 bit character set */

#  define	    NEXTCHAR	((pANTLR3_UINT8)(INPUT->nextChar))
#  define	    DATAP	((pANTLR3_UINT8)(INPUT->data))

# else

#  define	    NEXTCHAR	((pANTLR3_UINT16)(INPUT->nextChar))
#  define	    DATAP	((pANTLR3_UINT16)(INPUT->data))

# endif

# define	    LA(n) ((NEXTCHAR + n) > (DATAP + INPUT->sizeBuf) ? ANTLR3_CHARSTREAM_EOF : (ANTLR3_UCHAR)(*(NEXTCHAR + n - 1)))
# define            CONSUME()                                           \
{                                                                       \
    if        (NEXTCHAR < (DATAP + INPUT->sizeBuf))                     \
    {                                                                   \
        INPUT->charPositionInLine++;                                    \
        if  ((ANTLR3_UCHAR)(*NEXTCHAR) == INPUT->newlineChar)           \
        {                                                               \
            INPUT->line++;                                              \
            INPUT->charPositionInLine        = 0;                       \
            INPUT->currentLine                = (void *)(NEXTCHAR + 1); \
        }                                                               \
        INPUT->nextChar = (void *)(NEXTCHAR + 1);                       \
    }                                                                   \
}

#else

// Pick up the input character by calling the input stream implementation.
//
#define	    CONSUME()   INPUT->istream->consume(INPUT->istream)
#define	    LA(n)       INPUT->istream->_LA(INPUT->istream, n)

#endif

#define		TOKTEXT(tok, txt)				tok, (pANTLR3_UINT8)txt

/* The 4 tokens defined below may well clash with your own #defines or token types. If so
 * then for the present you must use different names for your defines as these are hard coded
 * in the code generator. It would be better not to use such names internally, and maybe
 * we can change this in a forthcoming release. I deliberately do not #undef these
 * here as this will at least give you a redefined error somewhere if they clash.
 */
#define	    UP	    ANTLR3_TOKEN_UP
#define	    DOWN    ANTLR3_TOKEN_DOWN
#define	    EOR	    ANTLR3_TOKEN_EOR
#define	    INVALID ANTLR3_TOKEN_INVALID


/* =============================================================================
 * Functions to create and destroy scopes. First come the rule scopes, followed
 * by the global declared scopes.
 */



/* ============================================================================= */

/* =============================================================================
 * Start of recognizer
 */

/* Forward declare the locally static matching functions we have generated and any predicate functions.
 */
static ANTLR3_INLINE 
 void
	mT__22    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mT__23    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mT__24    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mT__25    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mT__26    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mT__27    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mT__28    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mT__29    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mT__30    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mT__31    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mT__32    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mT__33    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mT__34    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mT__35    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mDIGIT    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mZERO    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mPOS_DIGIT    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mCOMMON_CHAR    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mHEX_CHAR    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mSPACE    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mLQUOTE    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mRQUOTE    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mCR    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mLF    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mDOT    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mEQUAL    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mCOLON    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mSLASH    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mDASH    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mCOMMA    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mSTAR    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mOCTET    (pbelle_sdpLexer ctx);
static ANTLR3_INLINE 
 void
	mTokens    (pbelle_sdpLexer ctx);
static void	belle_sdpLexerFree(pbelle_sdpLexer ctx);

/* =========================================================================
 * Lexer matching rules end.
 * =========================================================================
 */



static void
belle_sdpLexerFree  (pbelle_sdpLexer ctx)
{
    LEXER->free(LEXER);

    ANTLR3_FREE(ctx);
}

static void
belle_sdpLexerReset (pbelle_sdpLexer ctx)
{
    RECOGNIZER->reset(RECOGNIZER);
}

/** \brief Name of the grammar file that generated this code
 */
static const char fileName[] = "../grammars/belle_sdp.g";

/** \brief Return the name of the grammar file that generated this code.
 */
static const char * getGrammarFileName()
{
	return fileName;
}

/** \brief Create a new lexer called belle_sdpLexer
 *
 * \param[in]    instream Pointer to an initialized input stream
 * \return
 *     - Success pbelle_sdpLexer initialized for the lex start
 *     - Fail NULL
 */
ANTLR3_API pbelle_sdpLexer belle_sdpLexerNew
(
pANTLR3_INPUT_STREAM
 instream)
{
	// See if we can create a new lexer with the standard constructor
	//
	return belle_sdpLexerNewSSD(instream, NULL);
}

/** \brief Create a new lexer called belle_sdpLexer
 *
 * \param[in]    instream Pointer to an initialized input stream
 * \param[state] state Previously created shared recognizer stat
 * \return
 *     - Success pbelle_sdpLexer initialized for the lex start
 *     - Fail NULL
 */
ANTLR3_API pbelle_sdpLexer belle_sdpLexerNewSSD
(pANTLR3_INPUT_STREAM instream, pANTLR3_RECOGNIZER_SHARED_STATE state)
{
    pbelle_sdpLexer ctx; // Context structure we will build and return

    ctx = (pbelle_sdpLexer) ANTLR3_CALLOC(1, sizeof(belle_sdpLexer));

    if  (ctx == NULL)
    {
        // Failed to allocate memory for lexer context
        return  NULL;
    }

    /* -------------------------------------------------------------------
     * Memory for basic structure is allocated, now to fill in
     * in base ANTLR3 structures. We initialize the function pointers
     * for the standard ANTLR3 lexer function set, but upon return
     * from here, the programmer may set the pointers to provide custom
     * implementations of each function.
     *
     * We don't use the macros defined in belle_sdpLexer.h here so you can get a sense
     * of what goes where.
     */

    /* Create a base lexer, using the supplied input stream
     */
    ctx->pLexer	= antlr3LexerNewStream(ANTLR3_SIZE_HINT, instream, state);

    /* Check that we allocated the memory correctly
     */
    if	(ctx->pLexer == NULL)
    {
		ANTLR3_FREE(ctx);
		return  NULL;
    }
    /* Install the implementation of our belle_sdpLexer interface
     */
    ctx->mT__22	= mT__22;
    ctx->mT__23	= mT__23;
    ctx->mT__24	= mT__24;
    ctx->mT__25	= mT__25;
    ctx->mT__26	= mT__26;
    ctx->mT__27	= mT__27;
    ctx->mT__28	= mT__28;
    ctx->mT__29	= mT__29;
    ctx->mT__30	= mT__30;
    ctx->mT__31	= mT__31;
    ctx->mT__32	= mT__32;
    ctx->mT__33	= mT__33;
    ctx->mT__34	= mT__34;
    ctx->mT__35	= mT__35;
    ctx->mDIGIT	= mDIGIT;
    ctx->mZERO	= mZERO;
    ctx->mPOS_DIGIT	= mPOS_DIGIT;
    ctx->mCOMMON_CHAR	= mCOMMON_CHAR;
    ctx->mHEX_CHAR	= mHEX_CHAR;
    ctx->mSPACE	= mSPACE;
    ctx->mLQUOTE	= mLQUOTE;
    ctx->mRQUOTE	= mRQUOTE;
    ctx->mCR	= mCR;
    ctx->mLF	= mLF;
    ctx->mDOT	= mDOT;
    ctx->mEQUAL	= mEQUAL;
    ctx->mCOLON	= mCOLON;
    ctx->mSLASH	= mSLASH;
    ctx->mDASH	= mDASH;
    ctx->mCOMMA	= mCOMMA;
    ctx->mSTAR	= mSTAR;
    ctx->mOCTET	= mOCTET;
    ctx->mTokens	= mTokens;

    /** When the nextToken() call is made to this lexer's pANTLR3_TOKEN_SOURCE
     *  it will call mTokens() in this generated code, and will pass it the ctx
     * pointer of this lexer, not the context of the base lexer, so store that now.
     */
    ctx->pLexer->ctx	    = ctx;

    /**Install the token matching function
     */
    ctx->pLexer->mTokens = (void (*) (void *))(mTokens);

    ctx->getGrammarFileName	= getGrammarFileName;
    ctx->free		= belle_sdpLexerFree;
    ctx->reset          = belle_sdpLexerReset;


    /* Return the newly built lexer to the caller
     */
    return  ctx;
}
/* =========================================================================
 * Functions to match the lexer grammar defined tokens from the input stream
 */

//   Comes from: 36:7: ( '!' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__22
 *
 * Looks to match the characters the constitute the token T__22
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mT__22(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = T__22;


    // ../grammars/belle_sdp.g:36:7: ( '!' )
    // ../grammars/belle_sdp.g:36:9: '!'
    {
        MATCHC('!');
        if  (HASEXCEPTION())
        {
            goto ruleT__22Ex;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleT__22Ex; /* Prevent compiler warnings */
    ruleT__22Ex: ;

}
// $ANTLR end T__22

//   Comes from: 37:7: ( '#' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__23
 *
 * Looks to match the characters the constitute the token T__23
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mT__23(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = T__23;


    // ../grammars/belle_sdp.g:37:7: ( '#' )
    // ../grammars/belle_sdp.g:37:9: '#'
    {
        MATCHC('#');
        if  (HASEXCEPTION())
        {
            goto ruleT__23Ex;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleT__23Ex; /* Prevent compiler warnings */
    ruleT__23Ex: ;

}
// $ANTLR end T__23

//   Comes from: 38:7: ( '$' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__24
 *
 * Looks to match the characters the constitute the token T__24
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mT__24(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = T__24;


    // ../grammars/belle_sdp.g:38:7: ( '$' )
    // ../grammars/belle_sdp.g:38:9: '$'
    {
        MATCHC('$');
        if  (HASEXCEPTION())
        {
            goto ruleT__24Ex;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleT__24Ex; /* Prevent compiler warnings */
    ruleT__24Ex: ;

}
// $ANTLR end T__24

//   Comes from: 39:7: ( '%' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__25
 *
 * Looks to match the characters the constitute the token T__25
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mT__25(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = T__25;


    // ../grammars/belle_sdp.g:39:7: ( '%' )
    // ../grammars/belle_sdp.g:39:9: '%'
    {
        MATCHC('%');
        if  (HASEXCEPTION())
        {
            goto ruleT__25Ex;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleT__25Ex; /* Prevent compiler warnings */
    ruleT__25Ex: ;

}
// $ANTLR end T__25

//   Comes from: 40:7: ( '&' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__26
 *
 * Looks to match the characters the constitute the token T__26
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mT__26(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = T__26;


    // ../grammars/belle_sdp.g:40:7: ( '&' )
    // ../grammars/belle_sdp.g:40:9: '&'
    {
        MATCHC('&');
        if  (HASEXCEPTION())
        {
            goto ruleT__26Ex;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleT__26Ex; /* Prevent compiler warnings */
    ruleT__26Ex: ;

}
// $ANTLR end T__26

//   Comes from: 41:7: ( '+' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__27
 *
 * Looks to match the characters the constitute the token T__27
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mT__27(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = T__27;


    // ../grammars/belle_sdp.g:41:7: ( '+' )
    // ../grammars/belle_sdp.g:41:9: '+'
    {
        MATCHC('+');
        if  (HASEXCEPTION())
        {
            goto ruleT__27Ex;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleT__27Ex; /* Prevent compiler warnings */
    ruleT__27Ex: ;

}
// $ANTLR end T__27

//   Comes from: 42:7: ( '\\'' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__28
 *
 * Looks to match the characters the constitute the token T__28
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mT__28(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = T__28;


    // ../grammars/belle_sdp.g:42:7: ( '\\'' )
    // ../grammars/belle_sdp.g:42:9: '\\''
    {
        MATCHC('\'');
        if  (HASEXCEPTION())
        {
            goto ruleT__28Ex;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleT__28Ex; /* Prevent compiler warnings */
    ruleT__28Ex: ;

}
// $ANTLR end T__28

//   Comes from: 43:7: ( '^' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__29
 *
 * Looks to match the characters the constitute the token T__29
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mT__29(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = T__29;


    // ../grammars/belle_sdp.g:43:7: ( '^' )
    // ../grammars/belle_sdp.g:43:9: '^'
    {
        MATCHC('^');
        if  (HASEXCEPTION())
        {
            goto ruleT__29Ex;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleT__29Ex; /* Prevent compiler warnings */
    ruleT__29Ex: ;

}
// $ANTLR end T__29

//   Comes from: 44:7: ( '_' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__30
 *
 * Looks to match the characters the constitute the token T__30
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mT__30(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = T__30;


    // ../grammars/belle_sdp.g:44:7: ( '_' )
    // ../grammars/belle_sdp.g:44:9: '_'
    {
        MATCHC('_');
        if  (HASEXCEPTION())
        {
            goto ruleT__30Ex;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleT__30Ex; /* Prevent compiler warnings */
    ruleT__30Ex: ;

}
// $ANTLR end T__30

//   Comes from: 45:7: ( '`' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__31
 *
 * Looks to match the characters the constitute the token T__31
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mT__31(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = T__31;


    // ../grammars/belle_sdp.g:45:7: ( '`' )
    // ../grammars/belle_sdp.g:45:9: '`'
    {
        MATCHC('`');
        if  (HASEXCEPTION())
        {
            goto ruleT__31Ex;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleT__31Ex; /* Prevent compiler warnings */
    ruleT__31Ex: ;

}
// $ANTLR end T__31

//   Comes from: 46:7: ( '{' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__32
 *
 * Looks to match the characters the constitute the token T__32
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mT__32(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = T__32;


    // ../grammars/belle_sdp.g:46:7: ( '{' )
    // ../grammars/belle_sdp.g:46:9: '{'
    {
        MATCHC('{');
        if  (HASEXCEPTION())
        {
            goto ruleT__32Ex;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleT__32Ex; /* Prevent compiler warnings */
    ruleT__32Ex: ;

}
// $ANTLR end T__32

//   Comes from: 47:7: ( '|' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__33
 *
 * Looks to match the characters the constitute the token T__33
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mT__33(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = T__33;


    // ../grammars/belle_sdp.g:47:7: ( '|' )
    // ../grammars/belle_sdp.g:47:9: '|'
    {
        MATCHC('|');
        if  (HASEXCEPTION())
        {
            goto ruleT__33Ex;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleT__33Ex; /* Prevent compiler warnings */
    ruleT__33Ex: ;

}
// $ANTLR end T__33

//   Comes from: 48:7: ( '}' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__34
 *
 * Looks to match the characters the constitute the token T__34
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mT__34(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = T__34;


    // ../grammars/belle_sdp.g:48:7: ( '}' )
    // ../grammars/belle_sdp.g:48:9: '}'
    {
        MATCHC('}');
        if  (HASEXCEPTION())
        {
            goto ruleT__34Ex;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleT__34Ex; /* Prevent compiler warnings */
    ruleT__34Ex: ;

}
// $ANTLR end T__34

//   Comes from: 49:7: ( '~' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__35
 *
 * Looks to match the characters the constitute the token T__35
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mT__35(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = T__35;


    // ../grammars/belle_sdp.g:49:7: ( '~' )
    // ../grammars/belle_sdp.g:49:9: '~'
    {
        MATCHC('~');
        if  (HASEXCEPTION())
        {
            goto ruleT__35Ex;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleT__35Ex; /* Prevent compiler warnings */
    ruleT__35Ex: ;

}
// $ANTLR end T__35

//   Comes from: 578:6: ( ZERO | POS_DIGIT )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start DIGIT
 *
 * Looks to match the characters the constitute the token DIGIT
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mDIGIT(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = DIGIT;


    // ../grammars/belle_sdp.g:578:6: ( ZERO | POS_DIGIT )
    // ../grammars/belle_sdp.g:
    {
        if ( ((LA(1) >= '0') && (LA(1) <= '9')) )
        {
            CONSUME();
        }
        else
        {
            CONSTRUCTEX();
            EXCEPTION->type         = ANTLR3_MISMATCHED_SET_EXCEPTION;
            EXCEPTION->name         = (void *)ANTLR3_MISMATCHED_SET_NAME;

            LRECOVER();
            goto ruleDIGITEx;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleDIGITEx; /* Prevent compiler warnings */
    ruleDIGITEx: ;

}
// $ANTLR end DIGIT

//   Comes from: 579:14: ( '0' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start ZERO
 *
 * Looks to match the characters the constitute the token ZERO
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mZERO(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;


    // ../grammars/belle_sdp.g:579:14: ( '0' )
    // ../grammars/belle_sdp.g:579:16: '0'
    {
        MATCHC('0');
        if  (HASEXCEPTION())
        {
            goto ruleZEROEx;
        }


    }


    // This is where rules clean up and exit
    //
    goto ruleZEROEx; /* Prevent compiler warnings */
    ruleZEROEx: ;

}
// $ANTLR end ZERO

//   Comes from: 580:20: ( '1' .. '9' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start POS_DIGIT
 *
 * Looks to match the characters the constitute the token POS_DIGIT
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mPOS_DIGIT(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;


    // ../grammars/belle_sdp.g:580:20: ( '1' .. '9' )
    // ../grammars/belle_sdp.g:
    {
        if ( ((LA(1) >= '1') && (LA(1) <= '9')) )
        {
            CONSUME();
        }
        else
        {
            CONSTRUCTEX();
            EXCEPTION->type         = ANTLR3_MISMATCHED_SET_EXCEPTION;
            EXCEPTION->name         = (void *)ANTLR3_MISMATCHED_SET_NAME;

            LRECOVER();
            goto rulePOS_DIGITEx;
        }


    }


    // This is where rules clean up and exit
    //
    goto rulePOS_DIGITEx; /* Prevent compiler warnings */
    rulePOS_DIGITEx: ;

}
// $ANTLR end POS_DIGIT

//   Comes from: 583:3: ( 'g' .. 'z' | 'G' .. 'Z' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start COMMON_CHAR
 *
 * Looks to match the characters the constitute the token COMMON_CHAR
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mCOMMON_CHAR(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = COMMON_CHAR;


    // ../grammars/belle_sdp.g:583:3: ( 'g' .. 'z' | 'G' .. 'Z' )
    // ../grammars/belle_sdp.g:
    {
        if ( ((LA(1) >= 'G') && (LA(1) <= 'Z')) || ((LA(1) >= 'g') && (LA(1) <= 'z')) )
        {
            CONSUME();
        }
        else
        {
            CONSTRUCTEX();
            EXCEPTION->type         = ANTLR3_MISMATCHED_SET_EXCEPTION;
            EXCEPTION->name         = (void *)ANTLR3_MISMATCHED_SET_NAME;

            LRECOVER();
            goto ruleCOMMON_CHAREx;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleCOMMON_CHAREx; /* Prevent compiler warnings */
    ruleCOMMON_CHAREx: ;

}
// $ANTLR end COMMON_CHAR

//   Comes from: 584:9: ( 'a' .. 'f' | 'A' .. 'F' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start HEX_CHAR
 *
 * Looks to match the characters the constitute the token HEX_CHAR
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mHEX_CHAR(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = HEX_CHAR;


    // ../grammars/belle_sdp.g:584:9: ( 'a' .. 'f' | 'A' .. 'F' )
    // ../grammars/belle_sdp.g:
    {
        if ( ((LA(1) >= 'A') && (LA(1) <= 'F')) || ((LA(1) >= 'a') && (LA(1) <= 'f')) )
        {
            CONSUME();
        }
        else
        {
            CONSTRUCTEX();
            EXCEPTION->type         = ANTLR3_MISMATCHED_SET_EXCEPTION;
            EXCEPTION->name         = (void *)ANTLR3_MISMATCHED_SET_NAME;

            LRECOVER();
            goto ruleHEX_CHAREx;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleHEX_CHAREx; /* Prevent compiler warnings */
    ruleHEX_CHAREx: ;

}
// $ANTLR end HEX_CHAR

//   Comes from: 586:6: ( ' ' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start SPACE
 *
 * Looks to match the characters the constitute the token SPACE
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mSPACE(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = SPACE;


    // ../grammars/belle_sdp.g:586:6: ( ' ' )
    // ../grammars/belle_sdp.g:586:8: ' '
    {
        MATCHC(' ');
        if  (HASEXCEPTION())
        {
            goto ruleSPACEEx;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleSPACEEx; /* Prevent compiler warnings */
    ruleSPACEEx: ;

}
// $ANTLR end SPACE

//   Comes from: 589:7: ( '<' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start LQUOTE
 *
 * Looks to match the characters the constitute the token LQUOTE
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mLQUOTE(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = LQUOTE;


    // ../grammars/belle_sdp.g:589:7: ( '<' )
    // ../grammars/belle_sdp.g:589:9: '<'
    {
        MATCHC('<');
        if  (HASEXCEPTION())
        {
            goto ruleLQUOTEEx;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleLQUOTEEx; /* Prevent compiler warnings */
    ruleLQUOTEEx: ;

}
// $ANTLR end LQUOTE

//   Comes from: 590:7: ( '>' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start RQUOTE
 *
 * Looks to match the characters the constitute the token RQUOTE
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mRQUOTE(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = RQUOTE;


    // ../grammars/belle_sdp.g:590:7: ( '>' )
    // ../grammars/belle_sdp.g:590:9: '>'
    {
        MATCHC('>');
        if  (HASEXCEPTION())
        {
            goto ruleRQUOTEEx;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleRQUOTEEx; /* Prevent compiler warnings */
    ruleRQUOTEEx: ;

}
// $ANTLR end RQUOTE

//   Comes from: 591:3: ( '\\r' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start CR
 *
 * Looks to match the characters the constitute the token CR
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mCR(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = CR;


    // ../grammars/belle_sdp.g:591:3: ( '\\r' )
    // ../grammars/belle_sdp.g:591:4: '\\r'
    {
        MATCHC('\r');
        if  (HASEXCEPTION())
        {
            goto ruleCREx;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleCREx; /* Prevent compiler warnings */
    ruleCREx: ;

}
// $ANTLR end CR

//   Comes from: 592:3: ( '\\n' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start LF
 *
 * Looks to match the characters the constitute the token LF
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mLF(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = LF;


    // ../grammars/belle_sdp.g:592:3: ( '\\n' )
    // ../grammars/belle_sdp.g:592:4: '\\n'
    {
        MATCHC('\n');
        if  (HASEXCEPTION())
        {
            goto ruleLFEx;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleLFEx; /* Prevent compiler warnings */
    ruleLFEx: ;

}
// $ANTLR end LF

//   Comes from: 593:4: ( '.' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start DOT
 *
 * Looks to match the characters the constitute the token DOT
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mDOT(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = DOT;


    // ../grammars/belle_sdp.g:593:4: ( '.' )
    // ../grammars/belle_sdp.g:593:6: '.'
    {
        MATCHC('.');
        if  (HASEXCEPTION())
        {
            goto ruleDOTEx;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleDOTEx; /* Prevent compiler warnings */
    ruleDOTEx: ;

}
// $ANTLR end DOT

//   Comes from: 594:6: ( '=' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start EQUAL
 *
 * Looks to match the characters the constitute the token EQUAL
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mEQUAL(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = EQUAL;


    // ../grammars/belle_sdp.g:594:6: ( '=' )
    // ../grammars/belle_sdp.g:594:8: '='
    {
        MATCHC('=');
        if  (HASEXCEPTION())
        {
            goto ruleEQUALEx;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleEQUALEx; /* Prevent compiler warnings */
    ruleEQUALEx: ;

}
// $ANTLR end EQUAL

//   Comes from: 595:6: ( ':' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start COLON
 *
 * Looks to match the characters the constitute the token COLON
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mCOLON(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = COLON;


    // ../grammars/belle_sdp.g:595:6: ( ':' )
    // ../grammars/belle_sdp.g:595:8: ':'
    {
        MATCHC(':');
        if  (HASEXCEPTION())
        {
            goto ruleCOLONEx;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleCOLONEx; /* Prevent compiler warnings */
    ruleCOLONEx: ;

}
// $ANTLR end COLON

//   Comes from: 596:6: ( '/' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start SLASH
 *
 * Looks to match the characters the constitute the token SLASH
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mSLASH(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = SLASH;


    // ../grammars/belle_sdp.g:596:6: ( '/' )
    // ../grammars/belle_sdp.g:596:8: '/'
    {
        MATCHC('/');
        if  (HASEXCEPTION())
        {
            goto ruleSLASHEx;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleSLASHEx; /* Prevent compiler warnings */
    ruleSLASHEx: ;

}
// $ANTLR end SLASH

//   Comes from: 597:5: ( '-' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start DASH
 *
 * Looks to match the characters the constitute the token DASH
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mDASH(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = DASH;


    // ../grammars/belle_sdp.g:597:5: ( '-' )
    // ../grammars/belle_sdp.g:597:7: '-'
    {
        MATCHC('-');
        if  (HASEXCEPTION())
        {
            goto ruleDASHEx;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleDASHEx; /* Prevent compiler warnings */
    ruleDASHEx: ;

}
// $ANTLR end DASH

//   Comes from: 598:6: ( ',' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start COMMA
 *
 * Looks to match the characters the constitute the token COMMA
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mCOMMA(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = COMMA;


    // ../grammars/belle_sdp.g:598:6: ( ',' )
    // ../grammars/belle_sdp.g:598:8: ','
    {
        MATCHC(',');
        if  (HASEXCEPTION())
        {
            goto ruleCOMMAEx;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleCOMMAEx; /* Prevent compiler warnings */
    ruleCOMMAEx: ;

}
// $ANTLR end COMMA

//   Comes from: 599:5: ( '*' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start STAR
 *
 * Looks to match the characters the constitute the token STAR
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mSTAR(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = STAR;


    // ../grammars/belle_sdp.g:599:5: ( '*' )
    // ../grammars/belle_sdp.g:599:7: '*'
    {
        MATCHC('*');
        if  (HASEXCEPTION())
        {
            goto ruleSTAREx;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleSTAREx; /* Prevent compiler warnings */
    ruleSTAREx: ;

}
// $ANTLR end STAR

//   Comes from: 600:7: ( . )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start OCTET
 *
 * Looks to match the characters the constitute the token OCTET
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == ANTLR3_TRUE if an exception was thrown.
 */
static ANTLR3_INLINE
void mOCTET(pbelle_sdpLexer ctx)
{
	ANTLR3_UINT32	_type;

    _type	    = OCTET;


    // ../grammars/belle_sdp.g:600:7: ( . )
    // ../grammars/belle_sdp.g:600:9: .
    {
        MATCHANY();
        if  (HASEXCEPTION())
        {
            goto ruleOCTETEx;
        }


    }

	LEXSTATE->type = _type;
    // This is where rules clean up and exit
    //
    goto ruleOCTETEx; /* Prevent compiler warnings */
    ruleOCTETEx: ;

}
// $ANTLR end OCTET

/** This is the entry point in to the lexer from an object that
 *  wants to generate the next token, such as a pCOMMON_TOKEN_STREAM
 */
static void
mTokens(pbelle_sdpLexer ctx)
{
    {
        //  ../grammars/belle_sdp.g:1:8: ( T__22 | T__23 | T__24 | T__25 | T__26 | T__27 | T__28 | T__29 | T__30 | T__31 | T__32 | T__33 | T__34 | T__35 | DIGIT | COMMON_CHAR | HEX_CHAR | SPACE | LQUOTE | RQUOTE | CR | LF | DOT | EQUAL | COLON | SLASH | DASH | COMMA | STAR | OCTET )

        ANTLR3_UINT32 alt1;

        alt1=30;

        {
            int LA1_0 = LA(1);
            if ( (LA1_0 == '!'))
            {
                alt1=1;
            }
            else if ( (LA1_0 == '#'))
            {
                alt1=2;
            }
            else if ( (LA1_0 == '$'))
            {
                alt1=3;
            }
            else if ( (LA1_0 == '%'))
            {
                alt1=4;
            }
            else if ( (LA1_0 == '&'))
            {
                alt1=5;
            }
            else if ( (LA1_0 == '+'))
            {
                alt1=6;
            }
            else if ( (LA1_0 == '\''))
            {
                alt1=7;
            }
            else if ( (LA1_0 == '^'))
            {
                alt1=8;
            }
            else if ( (LA1_0 == '_'))
            {
                alt1=9;
            }
            else if ( (LA1_0 == '`'))
            {
                alt1=10;
            }
            else if ( (LA1_0 == '{'))
            {
                alt1=11;
            }
            else if ( (LA1_0 == '|'))
            {
                alt1=12;
            }
            else if ( (LA1_0 == '}'))
            {
                alt1=13;
            }
            else if ( (LA1_0 == '~'))
            {
                alt1=14;
            }
            else if ( (((LA1_0 >= '0') && (LA1_0 <= '9'))))
            {
                alt1=15;
            }
            else if ( (((LA1_0 >= 'G') && (LA1_0 <= 'Z')) || ((LA1_0 >= 'g') && (LA1_0 <= 'z'))))
            {
                alt1=16;
            }
            else if ( (((LA1_0 >= 'A') && (LA1_0 <= 'F')) || ((LA1_0 >= 'a') && (LA1_0 <= 'f'))))
            {
                alt1=17;
            }
            else if ( (LA1_0 == ' '))
            {
                alt1=18;
            }
            else if ( (LA1_0 == '<'))
            {
                alt1=19;
            }
            else if ( (LA1_0 == '>'))
            {
                alt1=20;
            }
            else if ( (LA1_0 == '\r'))
            {
                alt1=21;
            }
            else if ( (LA1_0 == '\n'))
            {
                alt1=22;
            }
            else if ( (LA1_0 == '.'))
            {
                alt1=23;
            }
            else if ( (LA1_0 == '='))
            {
                alt1=24;
            }
            else if ( (LA1_0 == ':'))
            {
                alt1=25;
            }
            else if ( (LA1_0 == '/'))
            {
                alt1=26;
            }
            else if ( (LA1_0 == '-'))
            {
                alt1=27;
            }
            else if ( (LA1_0 == ','))
            {
                alt1=28;
            }
            else if ( (LA1_0 == '*'))
            {
                alt1=29;
            }
            else if ( (((LA1_0 >= 0x0000) && (LA1_0 <= '\t')) || ((LA1_0 >= 0x000B) && (LA1_0 <= '\f')) || ((LA1_0 >= 0x000E) && (LA1_0 <= 0x001F)) || LA1_0 == '"' || ((LA1_0 >= '(') && (LA1_0 <= ')')) || LA1_0 == ';' || ((LA1_0 >= '?') && (LA1_0 <= '@')) || ((LA1_0 >= '[') && (LA1_0 <= ']')) || ((LA1_0 >= 0x007F) && (LA1_0 <= 0xFFFF))))
            {
                alt1=30;
            }
            else
            {

                CONSTRUCTEX();
                EXCEPTION->type         = ANTLR3_NO_VIABLE_ALT_EXCEPTION;
                EXCEPTION->message      = (void *)"";
                EXCEPTION->decisionNum  = 1;
                EXCEPTION->state        = 0;


                goto ruleTokensEx;

            }
        }
        switch (alt1)
        {
    	case 1:
    	    // ../grammars/belle_sdp.g:1:10: T__22
    	    {
    	        /* 1:10: T__22 */
    	        mT__22(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 2:
    	    // ../grammars/belle_sdp.g:1:16: T__23
    	    {
    	        /* 1:16: T__23 */
    	        mT__23(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 3:
    	    // ../grammars/belle_sdp.g:1:22: T__24
    	    {
    	        /* 1:22: T__24 */
    	        mT__24(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 4:
    	    // ../grammars/belle_sdp.g:1:28: T__25
    	    {
    	        /* 1:28: T__25 */
    	        mT__25(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 5:
    	    // ../grammars/belle_sdp.g:1:34: T__26
    	    {
    	        /* 1:34: T__26 */
    	        mT__26(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 6:
    	    // ../grammars/belle_sdp.g:1:40: T__27
    	    {
    	        /* 1:40: T__27 */
    	        mT__27(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 7:
    	    // ../grammars/belle_sdp.g:1:46: T__28
    	    {
    	        /* 1:46: T__28 */
    	        mT__28(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 8:
    	    // ../grammars/belle_sdp.g:1:52: T__29
    	    {
    	        /* 1:52: T__29 */
    	        mT__29(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 9:
    	    // ../grammars/belle_sdp.g:1:58: T__30
    	    {
    	        /* 1:58: T__30 */
    	        mT__30(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 10:
    	    // ../grammars/belle_sdp.g:1:64: T__31
    	    {
    	        /* 1:64: T__31 */
    	        mT__31(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 11:
    	    // ../grammars/belle_sdp.g:1:70: T__32
    	    {
    	        /* 1:70: T__32 */
    	        mT__32(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 12:
    	    // ../grammars/belle_sdp.g:1:76: T__33
    	    {
    	        /* 1:76: T__33 */
    	        mT__33(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 13:
    	    // ../grammars/belle_sdp.g:1:82: T__34
    	    {
    	        /* 1:82: T__34 */
    	        mT__34(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 14:
    	    // ../grammars/belle_sdp.g:1:88: T__35
    	    {
    	        /* 1:88: T__35 */
    	        mT__35(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 15:
    	    // ../grammars/belle_sdp.g:1:94: DIGIT
    	    {
    	        /* 1:94: DIGIT */
    	        mDIGIT(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 16:
    	    // ../grammars/belle_sdp.g:1:100: COMMON_CHAR
    	    {
    	        /* 1:100: COMMON_CHAR */
    	        mCOMMON_CHAR(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 17:
    	    // ../grammars/belle_sdp.g:1:112: HEX_CHAR
    	    {
    	        /* 1:112: HEX_CHAR */
    	        mHEX_CHAR(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 18:
    	    // ../grammars/belle_sdp.g:1:121: SPACE
    	    {
    	        /* 1:121: SPACE */
    	        mSPACE(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 19:
    	    // ../grammars/belle_sdp.g:1:127: LQUOTE
    	    {
    	        /* 1:127: LQUOTE */
    	        mLQUOTE(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 20:
    	    // ../grammars/belle_sdp.g:1:134: RQUOTE
    	    {
    	        /* 1:134: RQUOTE */
    	        mRQUOTE(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 21:
    	    // ../grammars/belle_sdp.g:1:141: CR
    	    {
    	        /* 1:141: CR */
    	        mCR(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 22:
    	    // ../grammars/belle_sdp.g:1:144: LF
    	    {
    	        /* 1:144: LF */
    	        mLF(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 23:
    	    // ../grammars/belle_sdp.g:1:147: DOT
    	    {
    	        /* 1:147: DOT */
    	        mDOT(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 24:
    	    // ../grammars/belle_sdp.g:1:151: EQUAL
    	    {
    	        /* 1:151: EQUAL */
    	        mEQUAL(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 25:
    	    // ../grammars/belle_sdp.g:1:157: COLON
    	    {
    	        /* 1:157: COLON */
    	        mCOLON(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 26:
    	    // ../grammars/belle_sdp.g:1:163: SLASH
    	    {
    	        /* 1:163: SLASH */
    	        mSLASH(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 27:
    	    // ../grammars/belle_sdp.g:1:169: DASH
    	    {
    	        /* 1:169: DASH */
    	        mDASH(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 28:
    	    // ../grammars/belle_sdp.g:1:174: COMMA
    	    {
    	        /* 1:174: COMMA */
    	        mCOMMA(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 29:
    	    // ../grammars/belle_sdp.g:1:180: STAR
    	    {
    	        /* 1:180: STAR */
    	        mSTAR(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 30:
    	    // ../grammars/belle_sdp.g:1:185: OCTET
    	    {
    	        /* 1:185: OCTET */
    	        mOCTET(ctx );
    	        if  (HASEXCEPTION())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;

        }
    }


    goto ruleTokensEx; /* Prevent compiler warnings */
ruleTokensEx: ;
}

/* =========================================================================
 * Lexer matching rules end.
 * =========================================================================
 */
/* End of Lexer code
 * ================================================
 * ================================================
 */


/* End of code
 * =============================================================================
 */
