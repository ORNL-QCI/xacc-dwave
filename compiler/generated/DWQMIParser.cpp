
// Generated from DWQMI.g4 by ANTLR 4.7.1


#include "DWQMIListener.h"

#include "DWQMIParser.h"


using namespace antlrcpp;
using namespace dwqmi;
using namespace antlr4;

DWQMIParser::DWQMIParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

DWQMIParser::~DWQMIParser() {
  delete _interpreter;
}

std::string DWQMIParser::getGrammarFileName() const {
  return "DWQMI.g4";
}

const std::vector<std::string>& DWQMIParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& DWQMIParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- MainprogContext ------------------------------------------------------------------

DWQMIParser::MainprogContext::MainprogContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DWQMIParser::ProgramContext* DWQMIParser::MainprogContext::program() {
  return getRuleContext<DWQMIParser::ProgramContext>(0);
}


size_t DWQMIParser::MainprogContext::getRuleIndex() const {
  return DWQMIParser::RuleMainprog;
}

void DWQMIParser::MainprogContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMainprog(this);
}

void DWQMIParser::MainprogContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMainprog(this);
}

DWQMIParser::MainprogContext* DWQMIParser::mainprog() {
  MainprogContext *_localctx = _tracker.createInstance<MainprogContext>(_ctx, getState());
  enterRule(_localctx, 0, DWQMIParser::RuleMainprog);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(34);
    program();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

DWQMIParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DWQMIParser::LineContext *> DWQMIParser::ProgramContext::line() {
  return getRuleContexts<DWQMIParser::LineContext>();
}

DWQMIParser::LineContext* DWQMIParser::ProgramContext::line(size_t i) {
  return getRuleContext<DWQMIParser::LineContext>(i);
}


size_t DWQMIParser::ProgramContext::getRuleIndex() const {
  return DWQMIParser::RuleProgram;
}

void DWQMIParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void DWQMIParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}

DWQMIParser::ProgramContext* DWQMIParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 2, DWQMIParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(37); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(36);
      line();
      setState(39); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DWQMIParser::T__0)
      | (1ULL << DWQMIParser::COMMENT)
      | (1ULL << DWQMIParser::ANNEAL)
      | (1ULL << DWQMIParser::INT)
      | (1ULL << DWQMIParser::EOL))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineContext ------------------------------------------------------------------

DWQMIParser::LineContext::LineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DWQMIParser::LineContext::EOL() {
  return getToken(DWQMIParser::EOL, 0);
}

std::vector<DWQMIParser::StatementContext *> DWQMIParser::LineContext::statement() {
  return getRuleContexts<DWQMIParser::StatementContext>();
}

DWQMIParser::StatementContext* DWQMIParser::LineContext::statement(size_t i) {
  return getRuleContext<DWQMIParser::StatementContext>(i);
}

DWQMIParser::CommentContext* DWQMIParser::LineContext::comment() {
  return getRuleContext<DWQMIParser::CommentContext>(0);
}


size_t DWQMIParser::LineContext::getRuleIndex() const {
  return DWQMIParser::RuleLine;
}

void DWQMIParser::LineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLine(this);
}

void DWQMIParser::LineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLine(this);
}

DWQMIParser::LineContext* DWQMIParser::line() {
  LineContext *_localctx = _tracker.createInstance<LineContext>(_ctx, getState());
  enterRule(_localctx, 4, DWQMIParser::RuleLine);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(50);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DWQMIParser::T__0:
      case DWQMIParser::ANNEAL:
      case DWQMIParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(42); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(41);
          statement();
          setState(44); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << DWQMIParser::T__0)
          | (1ULL << DWQMIParser::ANNEAL)
          | (1ULL << DWQMIParser::INT))) != 0));
        setState(46);
        match(DWQMIParser::EOL);
        break;
      }

      case DWQMIParser::COMMENT: {
        enterOuterAlt(_localctx, 2);
        setState(48);
        comment();
        break;
      }

      case DWQMIParser::EOL: {
        enterOuterAlt(_localctx, 3);
        setState(49);
        match(DWQMIParser::EOL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

DWQMIParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DWQMIParser::AnnealdeclContext* DWQMIParser::StatementContext::annealdecl() {
  return getRuleContext<DWQMIParser::AnnealdeclContext>(0);
}

DWQMIParser::InstContext* DWQMIParser::StatementContext::inst() {
  return getRuleContext<DWQMIParser::InstContext>(0);
}


size_t DWQMIParser::StatementContext::getRuleIndex() const {
  return DWQMIParser::RuleStatement;
}

void DWQMIParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void DWQMIParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

DWQMIParser::StatementContext* DWQMIParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 6, DWQMIParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(59);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DWQMIParser::T__0:
      case DWQMIParser::ANNEAL: {
        enterOuterAlt(_localctx, 1);
        setState(53);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == DWQMIParser::ANNEAL) {
          setState(52);
          annealdecl();
        }
        setState(55);
        match(DWQMIParser::T__0);
        break;
      }

      case DWQMIParser::INT: {
        enterOuterAlt(_localctx, 2);
        setState(56);
        inst();
        setState(57);
        match(DWQMIParser::T__0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommentContext ------------------------------------------------------------------

DWQMIParser::CommentContext::CommentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DWQMIParser::CommentContext::COMMENT() {
  return getToken(DWQMIParser::COMMENT, 0);
}


size_t DWQMIParser::CommentContext::getRuleIndex() const {
  return DWQMIParser::RuleComment;
}

void DWQMIParser::CommentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComment(this);
}

void DWQMIParser::CommentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComment(this);
}

DWQMIParser::CommentContext* DWQMIParser::comment() {
  CommentContext *_localctx = _tracker.createInstance<CommentContext>(_ctx, getState());
  enterRule(_localctx, 8, DWQMIParser::RuleComment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    match(DWQMIParser::COMMENT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InstContext ------------------------------------------------------------------

DWQMIParser::InstContext::InstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> DWQMIParser::InstContext::INT() {
  return getTokens(DWQMIParser::INT);
}

tree::TerminalNode* DWQMIParser::InstContext::INT(size_t i) {
  return getToken(DWQMIParser::INT, i);
}

DWQMIParser::IdContext* DWQMIParser::InstContext::id() {
  return getRuleContext<DWQMIParser::IdContext>(0);
}

DWQMIParser::RealContext* DWQMIParser::InstContext::real() {
  return getRuleContext<DWQMIParser::RealContext>(0);
}


size_t DWQMIParser::InstContext::getRuleIndex() const {
  return DWQMIParser::RuleInst;
}

void DWQMIParser::InstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInst(this);
}

void DWQMIParser::InstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInst(this);
}

DWQMIParser::InstContext* DWQMIParser::inst() {
  InstContext *_localctx = _tracker.createInstance<InstContext>(_ctx, getState());
  enterRule(_localctx, 10, DWQMIParser::RuleInst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(63);
    match(DWQMIParser::INT);
    setState(64);
    match(DWQMIParser::INT);
    setState(67);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DWQMIParser::ID: {
        setState(65);
        id();
        break;
      }

      case DWQMIParser::REAL: {
        setState(66);
        real();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnnealdeclContext ------------------------------------------------------------------

DWQMIParser::AnnealdeclContext::AnnealdeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DWQMIParser::AnnealContext* DWQMIParser::AnnealdeclContext::anneal() {
  return getRuleContext<DWQMIParser::AnnealContext>(0);
}

DWQMIParser::TaContext* DWQMIParser::AnnealdeclContext::ta() {
  return getRuleContext<DWQMIParser::TaContext>(0);
}

DWQMIParser::TpContext* DWQMIParser::AnnealdeclContext::tp() {
  return getRuleContext<DWQMIParser::TpContext>(0);
}

DWQMIParser::TqContext* DWQMIParser::AnnealdeclContext::tq() {
  return getRuleContext<DWQMIParser::TqContext>(0);
}

DWQMIParser::DirectionContext* DWQMIParser::AnnealdeclContext::direction() {
  return getRuleContext<DWQMIParser::DirectionContext>(0);
}


size_t DWQMIParser::AnnealdeclContext::getRuleIndex() const {
  return DWQMIParser::RuleAnnealdecl;
}

void DWQMIParser::AnnealdeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnnealdecl(this);
}

void DWQMIParser::AnnealdeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnnealdecl(this);
}

DWQMIParser::AnnealdeclContext* DWQMIParser::annealdecl() {
  AnnealdeclContext *_localctx = _tracker.createInstance<AnnealdeclContext>(_ctx, getState());
  enterRule(_localctx, 12, DWQMIParser::RuleAnnealdecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(69);
    anneal();
    setState(70);
    ta();
    setState(71);
    tp();
    setState(72);
    tq();
    setState(74);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DWQMIParser::T__1

    || _la == DWQMIParser::T__2) {
      setState(73);
      direction();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TaContext ------------------------------------------------------------------

DWQMIParser::TaContext::TaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DWQMIParser::IdContext* DWQMIParser::TaContext::id() {
  return getRuleContext<DWQMIParser::IdContext>(0);
}

DWQMIParser::RealContext* DWQMIParser::TaContext::real() {
  return getRuleContext<DWQMIParser::RealContext>(0);
}

tree::TerminalNode* DWQMIParser::TaContext::INT() {
  return getToken(DWQMIParser::INT, 0);
}


size_t DWQMIParser::TaContext::getRuleIndex() const {
  return DWQMIParser::RuleTa;
}

void DWQMIParser::TaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTa(this);
}

void DWQMIParser::TaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTa(this);
}

DWQMIParser::TaContext* DWQMIParser::ta() {
  TaContext *_localctx = _tracker.createInstance<TaContext>(_ctx, getState());
  enterRule(_localctx, 14, DWQMIParser::RuleTa);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(79);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DWQMIParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(76);
        id();
        break;
      }

      case DWQMIParser::REAL: {
        enterOuterAlt(_localctx, 2);
        setState(77);
        real();
        break;
      }

      case DWQMIParser::INT: {
        enterOuterAlt(_localctx, 3);
        setState(78);
        match(DWQMIParser::INT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TpContext ------------------------------------------------------------------

DWQMIParser::TpContext::TpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DWQMIParser::IdContext* DWQMIParser::TpContext::id() {
  return getRuleContext<DWQMIParser::IdContext>(0);
}

DWQMIParser::RealContext* DWQMIParser::TpContext::real() {
  return getRuleContext<DWQMIParser::RealContext>(0);
}

tree::TerminalNode* DWQMIParser::TpContext::INT() {
  return getToken(DWQMIParser::INT, 0);
}


size_t DWQMIParser::TpContext::getRuleIndex() const {
  return DWQMIParser::RuleTp;
}

void DWQMIParser::TpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTp(this);
}

void DWQMIParser::TpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTp(this);
}

DWQMIParser::TpContext* DWQMIParser::tp() {
  TpContext *_localctx = _tracker.createInstance<TpContext>(_ctx, getState());
  enterRule(_localctx, 16, DWQMIParser::RuleTp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(84);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DWQMIParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(81);
        id();
        break;
      }

      case DWQMIParser::REAL: {
        enterOuterAlt(_localctx, 2);
        setState(82);
        real();
        break;
      }

      case DWQMIParser::INT: {
        enterOuterAlt(_localctx, 3);
        setState(83);
        match(DWQMIParser::INT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TqContext ------------------------------------------------------------------

DWQMIParser::TqContext::TqContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DWQMIParser::IdContext* DWQMIParser::TqContext::id() {
  return getRuleContext<DWQMIParser::IdContext>(0);
}

DWQMIParser::RealContext* DWQMIParser::TqContext::real() {
  return getRuleContext<DWQMIParser::RealContext>(0);
}

tree::TerminalNode* DWQMIParser::TqContext::INT() {
  return getToken(DWQMIParser::INT, 0);
}


size_t DWQMIParser::TqContext::getRuleIndex() const {
  return DWQMIParser::RuleTq;
}

void DWQMIParser::TqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTq(this);
}

void DWQMIParser::TqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTq(this);
}

DWQMIParser::TqContext* DWQMIParser::tq() {
  TqContext *_localctx = _tracker.createInstance<TqContext>(_ctx, getState());
  enterRule(_localctx, 18, DWQMIParser::RuleTq);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(89);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DWQMIParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(86);
        id();
        break;
      }

      case DWQMIParser::REAL: {
        enterOuterAlt(_localctx, 2);
        setState(87);
        real();
        break;
      }

      case DWQMIParser::INT: {
        enterOuterAlt(_localctx, 3);
        setState(88);
        match(DWQMIParser::INT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnnealContext ------------------------------------------------------------------

DWQMIParser::AnnealContext::AnnealContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DWQMIParser::AnnealContext::ANNEAL() {
  return getToken(DWQMIParser::ANNEAL, 0);
}


size_t DWQMIParser::AnnealContext::getRuleIndex() const {
  return DWQMIParser::RuleAnneal;
}

void DWQMIParser::AnnealContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnneal(this);
}

void DWQMIParser::AnnealContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnneal(this);
}

DWQMIParser::AnnealContext* DWQMIParser::anneal() {
  AnnealContext *_localctx = _tracker.createInstance<AnnealContext>(_ctx, getState());
  enterRule(_localctx, 20, DWQMIParser::RuleAnneal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(91);
    match(DWQMIParser::ANNEAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdContext ------------------------------------------------------------------

DWQMIParser::IdContext::IdContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DWQMIParser::IdContext::ID() {
  return getToken(DWQMIParser::ID, 0);
}


size_t DWQMIParser::IdContext::getRuleIndex() const {
  return DWQMIParser::RuleId;
}

void DWQMIParser::IdContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterId(this);
}

void DWQMIParser::IdContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitId(this);
}

DWQMIParser::IdContext* DWQMIParser::id() {
  IdContext *_localctx = _tracker.createInstance<IdContext>(_ctx, getState());
  enterRule(_localctx, 22, DWQMIParser::RuleId);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(93);
    match(DWQMIParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RealContext ------------------------------------------------------------------

DWQMIParser::RealContext::RealContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DWQMIParser::RealContext::REAL() {
  return getToken(DWQMIParser::REAL, 0);
}


size_t DWQMIParser::RealContext::getRuleIndex() const {
  return DWQMIParser::RuleReal;
}

void DWQMIParser::RealContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReal(this);
}

void DWQMIParser::RealContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReal(this);
}

DWQMIParser::RealContext* DWQMIParser::real() {
  RealContext *_localctx = _tracker.createInstance<RealContext>(_ctx, getState());
  enterRule(_localctx, 24, DWQMIParser::RuleReal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    match(DWQMIParser::REAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringContext ------------------------------------------------------------------

DWQMIParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DWQMIParser::StringContext::STRING() {
  return getToken(DWQMIParser::STRING, 0);
}


size_t DWQMIParser::StringContext::getRuleIndex() const {
  return DWQMIParser::RuleString;
}

void DWQMIParser::StringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString(this);
}

void DWQMIParser::StringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString(this);
}

DWQMIParser::StringContext* DWQMIParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 26, DWQMIParser::RuleString);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(97);
    match(DWQMIParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DirectionContext ------------------------------------------------------------------

DWQMIParser::DirectionContext::DirectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DWQMIParser::ForwardContext* DWQMIParser::DirectionContext::forward() {
  return getRuleContext<DWQMIParser::ForwardContext>(0);
}

DWQMIParser::ReverseContext* DWQMIParser::DirectionContext::reverse() {
  return getRuleContext<DWQMIParser::ReverseContext>(0);
}


size_t DWQMIParser::DirectionContext::getRuleIndex() const {
  return DWQMIParser::RuleDirection;
}

void DWQMIParser::DirectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDirection(this);
}

void DWQMIParser::DirectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDirection(this);
}

DWQMIParser::DirectionContext* DWQMIParser::direction() {
  DirectionContext *_localctx = _tracker.createInstance<DirectionContext>(_ctx, getState());
  enterRule(_localctx, 28, DWQMIParser::RuleDirection);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(101);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DWQMIParser::T__1: {
        enterOuterAlt(_localctx, 1);
        setState(99);
        forward();
        break;
      }

      case DWQMIParser::T__2: {
        enterOuterAlt(_localctx, 2);
        setState(100);
        reverse();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForwardContext ------------------------------------------------------------------

DWQMIParser::ForwardContext::ForwardContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DWQMIParser::ForwardContext::getRuleIndex() const {
  return DWQMIParser::RuleForward;
}

void DWQMIParser::ForwardContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForward(this);
}

void DWQMIParser::ForwardContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForward(this);
}

DWQMIParser::ForwardContext* DWQMIParser::forward() {
  ForwardContext *_localctx = _tracker.createInstance<ForwardContext>(_ctx, getState());
  enterRule(_localctx, 30, DWQMIParser::RuleForward);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(103);
    match(DWQMIParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReverseContext ------------------------------------------------------------------

DWQMIParser::ReverseContext::ReverseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DWQMIParser::ReverseContext::getRuleIndex() const {
  return DWQMIParser::RuleReverse;
}

void DWQMIParser::ReverseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReverse(this);
}

void DWQMIParser::ReverseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DWQMIListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReverse(this);
}

DWQMIParser::ReverseContext* DWQMIParser::reverse() {
  ReverseContext *_localctx = _tracker.createInstance<ReverseContext>(_ctx, getState());
  enterRule(_localctx, 32, DWQMIParser::RuleReverse);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(105);
    match(DWQMIParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> DWQMIParser::_decisionToDFA;
atn::PredictionContextCache DWQMIParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN DWQMIParser::_atn;
std::vector<uint16_t> DWQMIParser::_serializedATN;

std::vector<std::string> DWQMIParser::_ruleNames = {
  "mainprog", "program", "line", "statement", "comment", "inst", "annealdecl", 
  "ta", "tp", "tq", "anneal", "id", "real", "string", "direction", "forward", 
  "reverse"
};

std::vector<std::string> DWQMIParser::_literalNames = {
  "", "';'", "'forward'", "'reverse'", "", "'anneal'", "", "", "'-'"
};

std::vector<std::string> DWQMIParser::_symbolicNames = {
  "", "", "", "", "COMMENT", "ANNEAL", "ID", "REAL", "MINUS", "INT", "STRING", 
  "EOL", "WS"
};

dfa::Vocabulary DWQMIParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> DWQMIParser::_tokenNames;

DWQMIParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0xe, 0x6e, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x6, 0x3, 0x28, 0xa, 0x3, 0xd, 
    0x3, 0xe, 0x3, 0x29, 0x3, 0x4, 0x6, 0x4, 0x2d, 0xa, 0x4, 0xd, 0x4, 0xe, 
    0x4, 0x2e, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x35, 0xa, 
    0x4, 0x3, 0x5, 0x5, 0x5, 0x38, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x5, 0x5, 0x3e, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x46, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x4d, 0xa, 0x8, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x5, 0x9, 0x52, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x5, 0xa, 0x57, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x5c, 
    0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x68, 0xa, 0x10, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x2, 0x2, 0x13, 
    0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
    0x1c, 0x1e, 0x20, 0x22, 0x2, 0x2, 0x2, 0x6b, 0x2, 0x24, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x27, 0x3, 0x2, 0x2, 0x2, 0x6, 0x34, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x3d, 0x3, 0x2, 0x2, 0x2, 0xa, 0x3f, 0x3, 0x2, 0x2, 0x2, 0xc, 0x41, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x47, 0x3, 0x2, 0x2, 0x2, 0x10, 0x51, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x56, 0x3, 0x2, 0x2, 0x2, 0x14, 0x5b, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x18, 0x5f, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x61, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x63, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x67, 0x3, 0x2, 0x2, 0x2, 0x20, 0x69, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0x6b, 0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 0x5, 0x4, 0x3, 0x2, 0x25, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x26, 0x28, 0x5, 0x6, 0x4, 0x2, 0x27, 0x26, 0x3, 
    0x2, 0x2, 0x2, 0x28, 0x29, 0x3, 0x2, 0x2, 0x2, 0x29, 0x27, 0x3, 0x2, 
    0x2, 0x2, 0x29, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x2b, 0x2d, 0x5, 0x8, 0x5, 0x2, 0x2c, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0x2d, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x2f, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 
    0x7, 0xd, 0x2, 0x2, 0x31, 0x35, 0x3, 0x2, 0x2, 0x2, 0x32, 0x35, 0x5, 
    0xa, 0x6, 0x2, 0x33, 0x35, 0x7, 0xd, 0x2, 0x2, 0x34, 0x2c, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0x32, 0x3, 0x2, 0x2, 0x2, 0x34, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x35, 0x7, 0x3, 0x2, 0x2, 0x2, 0x36, 0x38, 0x5, 0xe, 0x8, 0x2, 
    0x37, 0x36, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x3, 0x2, 0x2, 0x2, 0x38, 
    0x39, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3e, 0x7, 0x3, 0x2, 0x2, 0x3a, 0x3b, 
    0x5, 0xc, 0x7, 0x2, 0x3b, 0x3c, 0x7, 0x3, 0x2, 0x2, 0x3c, 0x3e, 0x3, 
    0x2, 0x2, 0x2, 0x3d, 0x37, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3a, 0x3, 0x2, 
    0x2, 0x2, 0x3e, 0x9, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x7, 0x6, 0x2, 
    0x2, 0x40, 0xb, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x7, 0xb, 0x2, 0x2, 
    0x42, 0x45, 0x7, 0xb, 0x2, 0x2, 0x43, 0x46, 0x5, 0x18, 0xd, 0x2, 0x44, 
    0x46, 0x5, 0x1a, 0xe, 0x2, 0x45, 0x43, 0x3, 0x2, 0x2, 0x2, 0x45, 0x44, 
    0x3, 0x2, 0x2, 0x2, 0x46, 0xd, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x5, 
    0x16, 0xc, 0x2, 0x48, 0x49, 0x5, 0x10, 0x9, 0x2, 0x49, 0x4a, 0x5, 0x12, 
    0xa, 0x2, 0x4a, 0x4c, 0x5, 0x14, 0xb, 0x2, 0x4b, 0x4d, 0x5, 0x1e, 0x10, 
    0x2, 0x4c, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x3, 0x2, 0x2, 0x2, 
    0x4d, 0xf, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x52, 0x5, 0x18, 0xd, 0x2, 0x4f, 
    0x52, 0x5, 0x1a, 0xe, 0x2, 0x50, 0x52, 0x7, 0xb, 0x2, 0x2, 0x51, 0x4e, 
    0x3, 0x2, 0x2, 0x2, 0x51, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x50, 0x3, 
    0x2, 0x2, 0x2, 0x52, 0x11, 0x3, 0x2, 0x2, 0x2, 0x53, 0x57, 0x5, 0x18, 
    0xd, 0x2, 0x54, 0x57, 0x5, 0x1a, 0xe, 0x2, 0x55, 0x57, 0x7, 0xb, 0x2, 
    0x2, 0x56, 0x53, 0x3, 0x2, 0x2, 0x2, 0x56, 0x54, 0x3, 0x2, 0x2, 0x2, 
    0x56, 0x55, 0x3, 0x2, 0x2, 0x2, 0x57, 0x13, 0x3, 0x2, 0x2, 0x2, 0x58, 
    0x5c, 0x5, 0x18, 0xd, 0x2, 0x59, 0x5c, 0x5, 0x1a, 0xe, 0x2, 0x5a, 0x5c, 
    0x7, 0xb, 0x2, 0x2, 0x5b, 0x58, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 0x3, 
    0x2, 0x2, 0x2, 0x5b, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0x5d, 0x5e, 0x7, 0x7, 0x2, 0x2, 0x5e, 0x17, 0x3, 0x2, 0x2, 
    0x2, 0x5f, 0x60, 0x7, 0x8, 0x2, 0x2, 0x60, 0x19, 0x3, 0x2, 0x2, 0x2, 
    0x61, 0x62, 0x7, 0x9, 0x2, 0x2, 0x62, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x63, 
    0x64, 0x7, 0xc, 0x2, 0x2, 0x64, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x65, 0x68, 
    0x5, 0x20, 0x11, 0x2, 0x66, 0x68, 0x5, 0x22, 0x12, 0x2, 0x67, 0x65, 
    0x3, 0x2, 0x2, 0x2, 0x67, 0x66, 0x3, 0x2, 0x2, 0x2, 0x68, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0x69, 0x6a, 0x7, 0x4, 0x2, 0x2, 0x6a, 0x21, 0x3, 0x2, 
    0x2, 0x2, 0x6b, 0x6c, 0x7, 0x5, 0x2, 0x2, 0x6c, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0xd, 0x29, 0x2e, 0x34, 0x37, 0x3d, 0x45, 0x4c, 0x51, 0x56, 0x5b, 
    0x67, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

DWQMIParser::Initializer DWQMIParser::_init;
