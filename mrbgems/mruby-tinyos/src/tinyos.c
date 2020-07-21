#include <kern/types.h>
#include <mruby.h>
#include <mruby/array.h>

u8 in8(u16 port);
u16 in16(u16 port);
u32 in32(u16 port);
void out8(u16 port, u8 val);
void out16(u16 port, u16 val);
void out32(u16 port, u32 val);

static mrb_value
ioport_in8(mrb_state *mrb, mrb_value obj)
{
  mrb_int port;
  u8 val;

  mrb_get_args(mrb, "i", &port);
  val = in8((u16)port);

  return mrb_fixnum_value(val);
}

static mrb_value
ioport_in16(mrb_state *mrb, mrb_value obj)
{
  mrb_int port;
  u16 val;

  mrb_get_args(mrb, "i", &port);
  val = in16((u16)port);

  return mrb_fixnum_value(val);
}

static mrb_value
ioport_in32(mrb_state *mrb, mrb_value obj)
{
  mrb_int port;
  u32 val;

  mrb_get_args(mrb, "i", &port);
  val = in32((u16)port);

  return mrb_fixnum_value(val);
}

static mrb_value
ioport_out8(mrb_state *mrb, mrb_value obj)
{
  mrb_int port, val;

  mrb_get_args(mrb, "ii", &port, &val);
  out8((u16)port, (u8)val);

  return mrb_nil_value();
}

static mrb_value
ioport_out16(mrb_state *mrb, mrb_value obj)
{
  mrb_int port, val;

  mrb_get_args(mrb, "ii", &port, &val);
  out8((u16)port, (u16)val);

  return mrb_nil_value();
}

static mrb_value
ioport_out32(mrb_state *mrb, mrb_value obj)
{
  mrb_int port, val;

  mrb_get_args(mrb, "ii", &port, &val);
  out8((u16)port, (u32)val);

  return mrb_nil_value();
}

void
mrb_mruby_tinyos_gem_init(mrb_state* mrb)
{
  struct RClass *mrb_ioport;
  mrb_ioport = mrb_define_module(mrb, "IOPort");

  mrb_define_module_function(mrb, mrb_ioport, "in_8", ioport_in8, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, mrb_ioport, "in_16", ioport_in16, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, mrb_ioport, "in_32", ioport_in32, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, mrb_ioport, "out_8", ioport_out8, MRB_ARGS_REQ(2));
  mrb_define_module_function(mrb, mrb_ioport, "out_16", ioport_out16, MRB_ARGS_REQ(2));
  mrb_define_module_function(mrb, mrb_ioport, "out_32", ioport_out32, MRB_ARGS_REQ(2));
}

void
mrb_mruby_tinyos_gem_final(mrb_state* mrb)
{
}
