[@bs.module "react-simple-maps"]
external composableMapClass : ReasonReact.reactClass = "ComposableMap";

[@bs.deriving abstract]
type projectionConfig = {
  [@bs.optional]
  scale: int,
  [@bs.optional]
  xOffset: int,
  [@bs.optional]
  yOffset: int,
  [@bs.optional]
  rotation: (float, float, float),
  [@bs.optional]
  precision: float,
};

module Props = {
  [@bs.deriving abstract]
  type jsProps = {
    width: int,
    height: int,
    projection: string,
    projectionAsMethod: unit => unit,
    projectionConfig,
  };
};

let fromOption = Js.Nullable.fromOption;

let make =
    (
      ~width=800,
      ~height=450,
      ~projection="times",
      ~projectionAsMethod=?,
      ~projectionConfig,
      children,
    ) => {
  let projectionProp =
    switch (projectionAsMethod) {
    | None => projection
    | Some(arg) => arg
    };
  ReasonReact.wrapJsForReason(
    ~reactClass=composableMapClass,
    ~props=
      Props.jsProps(
        ~width,
        ~height,
        ~projection=projectionProp,
        ~projectionConfig,
      ),
    children,
  );
};
